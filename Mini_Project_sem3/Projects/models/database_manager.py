import mysql.connector

class DatabaseManager:
    def __init__(self):
        self.conn = mysql.connector.connect(
            host="localhost",
            user="root",
            password="new_password",  # Replace with your MySQL root password
            database="carbon_tracker"  # Replace with your database name
        )
        self.cursor = self.conn.cursor()

    def execute_query(self, query, values=None):
        self.cursor.execute(query, values)
        self.conn.commit()

    def fetch_all(self, query, values=None):
        self.cursor.execute(query, values)
        return self.cursor.fetchall()

    def fetch_one(self, query, values=None):
        self.cursor.execute(query, values)
        return self.cursor.fetchone()

    def close_connection(self):
        self.cursor.close()
        self.conn.close()
    
    def initialize_database(self):
        """
        Creates the necessary tables if they do not already exist.
        """
        # Create `users` table
        self.cursor.execute("CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY,username VARCHAR(50) NOT NULL UNIQUE,password VARCHAR(50) NOT NULL);")
        print("user table created !!!")

        # Create `activities` table
        self.cursor.execute("CREATE TABLE IF NOT EXISTS activities (id INT AUTO_INCREMENT PRIMARY KEY,user_id INT NOT NULL,activity_type VARCHAR(50) NOT NULL,value FLOAT NOT NULL,timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE);")

# If this file is run directly, initialize the database
if __name__ == "__main__":
    db = DatabaseManager()
    db.initialize_database()
    print("Database initialized, and tables are created if they did not exist.")
    db.close_connection()
