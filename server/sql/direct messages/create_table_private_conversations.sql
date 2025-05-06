CREATE TABLE private_conversations (
    conversation_id SERIAL PRIMARY KEY,
    user_1_id INT REFERENCES users(user_id),
    user_2_id INT REFERENCES users(user_id),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);