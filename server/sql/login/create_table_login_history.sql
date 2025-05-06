CREATE TABLE login_history (
    login_id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(user_id),
    login_timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    ip_address VARCHAR(255)
);