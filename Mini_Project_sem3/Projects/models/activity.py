from models.database_manager import DatabaseManager
from datetime import datetime, timedelta

class Activity:
    def __init__(self, user_id, activity_type, value):
        self.user_id = user_id
        self.activity_type = activity_type
        self.value = value

    def save_activity(self):
        db = DatabaseManager()
        query = "INSERT INTO activities (user_id, activity_type, value, timestamp)VALUES (%s, %s, %s, NOW())"
        db.execute_query(query, (self.user_id, self.activity_type, self.value))
        db.close_connection()

    @staticmethod
    def get_user_activities(user_id):
        db = DatabaseManager()
        query = "SELECT * FROM activities WHERE user_id = %s"
        results = db.fetch_all(query, (user_id,))
        db.close_connection()
        return results

    @staticmethod
    def get_emissions_by_period(user_id, period):
        """
        Fetch emissions data grouped by day or month for the specified period.
        :param user_id: ID of the user
        :param period: "weekly" or "monthly"
        :return: List of tuples [(date, total_emission), ...]
        """
        db = DatabaseManager()
        if period == "weekly":
            start_date = datetime.now() - timedelta(days=7)
            query = "SELECT DATE(timestamp) as date, SUM(value * CASE WHEN activity_type='transportation' THEN 0.21 WHEN activity_type='electricity' THEN 0.5 WHEN activity_type='food' THEN 2.5 WHEN activity_type='waste' THEN 1.2 END) as total_emission FROM activities WHERE user_id = %s AND timestamp >= %s GROUP BY DATE(timestamp) ORDER BY DATE(timestamp)"
            results = db.fetch_all(query, (user_id, start_date))
        elif period == "monthly":
            start_date = datetime.now() - timedelta(days=30)
            query = "SELECT DATE(timestamp) as date, SUM(value * CASE WHEN activity_type='transportation' THEN 0.21 WHEN activity_type='electricity' THEN 0.5 WHEN activity_type='food' THEN 2.5 WHEN activity_type='waste' THEN 1.2 END) as total_emission FROM activities WHERE user_id = %s AND timestamp >= %s GROUP BY DATE(timestamp) ORDER BY DATE(timestamp)"
            results = db.fetch_all(query, (user_id, start_date))
        else:
            results = []
        db.close_connection()
        return results