# Importing necessary libraries
import random

# Movie dataset with emotions
movie_data = {
    "happy": [
        "The Pursuit of Happyness",
        "La La Land",
        "Forrest Gump",
        "Up",
        "The Secret Life of Walter Mitty"
    ],
    "sad": [
        "The Fault in Our Stars",
        "A Beautiful Mind",
        "Schindler's List",
        "Manchester by the Sea",
        "Requiem for a Dream"
    ],
    "angry": [
        "The Dark Knight",
        "Gladiator",
        "John Wick",
        "Fight Club",
        "Mad Max: Fury Road"
    ],
    "fear": [
        "A Quiet Place",
        "Get Out",
        "The Conjuring",
        "It",
        "The Babadook"
    ],
    "excited": [
        "Avengers: Endgame",
        "Inception",
        "Spider-Man: No Way Home",
        "Jurassic Park",
        "The Matrix"
    ],
    "romantic": [
        "The Notebook",
        "Titanic",
        "Pride and Prejudice",
        "Crazy, Stupid, Love",
        "To All the Boys I've Loved Before"
    ]
}

# Function to recommend movies based on emotion
def recommend_movie(emotion):
    # Check if the emotion exists in the dataset
    if emotion in movie_data:
        # Recommend a random movie from the list
        return random.choice(movie_data[emotion])
    else:
        return "Sorry, I don't have movie recommendations for this emotion."

# Main Program
print("Welcome to the Emotion-Based Movie Recommendation System!")
user_emotion = input("How are you feeling today? (e.g., happy, sad, angry, excited, romantic or fear !!? ): ").strip().lower()

# Get movie recommendation
movie = recommend_movie(user_emotion)
print(f"We recommend you watch: {movie}")