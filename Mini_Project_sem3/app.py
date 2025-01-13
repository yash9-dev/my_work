from __init__ import create_app, db
from flask import request, jsonify, render_template
from models import UserActivity
from calculations import calculate_footprint

app = create_app()

@app.route("/")
def health_check():
    return render_template('forfun.html') 
    #return jsonify({"message": "API is running!"})

@app.route("/login")
def health_checku():
    return render_template('hehe.html') 
    #return jsonify({"message": "API is running!"})


@app.route("/api/calculate", methods=["POST"])
def calculate():
    try:
        data = request.json
        result = calculate_footprint(data)

        # Save to database
        activity = UserActivity(
            user_id=data.get("user_id"),
            activity=data.get("activity"),
            value=data.get("value"),
            carbon_footprint=result
        )
        with app.app_context():
            db.session.add(activity)
            db.session.commit()

        return jsonify({"carbon_footprint": result, "message": "Calculation successful!"}), 200
    except Exception as e:
        return jsonify({"error": str(e)}), 400

@app.route("/api/history/<int:user_id>", methods=["GET"])
def history(user_id):
    activities = UserActivity.query.filter_by(user_id=user_id).all()
    result = [
        {
            "activity": activity.activity,
            "value": activity.value,
            "carbon_footprint": activity.carbon_footprint,
            "timestamp": activity.timestamp
        } for activity in activities
    ]
    return jsonify(result), 200

if __name__ == "__main__":
    app.run(debug=True)
app.run(port=8080)