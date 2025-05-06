CREATE TABLE messages (
    message_id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(user_id),
    content TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);