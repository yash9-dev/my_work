from models.database_manager import DatabaseManager

class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

    def register_user(self):
        db = DatabaseManager()
        query = "INSERT INTO users (username, password) VALUES (%s, %s)"
        db.execute_query(query, (self.username, self.password))
        db.close_connection()

    @staticmethod
    def authenticate(username, password):
        db = DatabaseManager()
        query = "SELECT * FROM users WHERE username = %s AND password = %s"
        result = db.fetch_one(query, (username, password))
        db.close_connection()
        return result
