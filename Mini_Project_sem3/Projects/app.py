from flask import Flask, render_template, request, redirect, session
from models.user import User
from models.activity import Activity

app = Flask(__name__)
app.secret_key = "super_secret_key"

# Route: Home
@app.route("/")
def home():
    return redirect("/login")

# Route: Login
@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        user = User.authenticate(username, password)
        if user:
            session["user_id"] = user[0]
            return redirect("/dashboard")
        else:
            return render_template("login.html", error="Invalid credentials")
    return render_template("login.html")

# Route: Register
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        user = User(username, password)
        user.register_user()
        return redirect("/login")
    return render_template("register.html")

# Route: Dashboard
@app.route("/dashboard")
def dashboard():
    if "user_id" not in session:
        return redirect("/login")
    user_id = session["user_id"]
    activities = Activity.get_user_activities(user_id)
    return render_template("dashboard.html", activities=activities)

# Route: Add Activity
@app.route("/add_activity", methods=["GET", "POST"])
def add_activity():
    if "user_id" not in session:
        return redirect("/login")
    if request.method == "POST":
        activity_type = request.form["activity_type"]
        value = float(request.form["value"])

        activity = Activity(session["user_id"], activity_type, value)
        activity.save_activity()
        return redirect("/dashboard")
    return render_template("add_activity.html")

# Route: View Summary
@app.route("/view_summary/<string:period>")
def view_summary(period):
    if "user_id" not in session:
        return redirect("/login")

    user_id = session["user_id"]
    emission_data = Activity.get_emissions_by_period(user_id, period)

    if not emission_data:
        return render_template("view_summary.html", message="No data available for this period.")

    # Create graph using matplotlib
    import matplotlib.pyplot as plt
    import io
    import base64

    dates = [str(record[0]) for record in emission_data]
    emissions = [record[1] for record in emission_data]

    plt.figure(figsize=(10, 6))
    plt.bar(dates, emissions, color="skyblue")
    plt.xlabel("Date")
    plt.ylabel("Total Emissions (kg CO2)")
    plt.title(f"{period.capitalize()} Emission Summary")
    plt.xticks(rotation=45)
    plt.tight_layout()

    buffer = io.BytesIO()
    plt.savefig(buffer, format="png")
    buffer.seek(0)
    image_base64 = base64.b64encode(buffer.getvalue()).decode("utf-8")
    buffer.close()
    plt.close()

    return render_template("view_summary.html", graph=image_base64, period=period)

# Route: Logout
@app.route("/logout")
def logout():
    session.clear()
    return redirect("/login")

if __name__ == "__main__":
    app.run(debug=True)
