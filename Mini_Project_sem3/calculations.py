# Emission factors in kg CO2 per unit
EMISSION_FACTORS = {
    "transportation": 0.21,  # Example: 0.21 kg CO2 per km driven
    "electricity": 0.5,      # Example: 0.5 kg CO2 per kWh
    "food": 2.5,             # Example: 2.5 kg CO2 per meal
    "waste": 1.2             # Example: 1.2 kg CO2 per kg of waste
}

def calculate_footprint(data):
    activity = data.get("activity")
    value = data.get("value")
    if activity not in EMISSION_FACTORS:
        raise ValueError(f"Unknown activity: {activity}")
    return value * EMISSION_FACTORS[activity]
