from __init__ import db
from datetime import datetime

class UserActivity(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, nullable=False)
    activity = db.Column(db.String(50), nullable=False)
    value = db.Column(db.Float, nullable=False)
    carbon_footprint = db.Column(db.Float, nullable=False)
    timestamp = db.Column(db.DateTime, default=datetime.utcnow)

    def __repr__(self):
        return f"<UserActivity {self.activity} - {self.carbon_footprint}kg CO2>"
