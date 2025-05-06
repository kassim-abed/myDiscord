CREATE TABLE reactions (
    reaction_id SERIAL PRIMARY KEY,
    message_id INT REFERENCES messages(message_id),
    user_id INT REFERENCES users(user_id),
    emoji VARCHAR(10),  -- Par exemple, :thumbsup:
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);