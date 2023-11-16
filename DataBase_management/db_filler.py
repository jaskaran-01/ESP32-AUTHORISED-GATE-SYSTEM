import random
import string
from datetime import datetime, timedelta
import mysql.connector

def generate_uid():
    return ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(8, 10)))

# Function to generate a random Registration Number (RegNo)
def generate_regno():
    return f'2293{random.randint(10000, 99999)}'

# Function to generate a random datetime before 11/7/2023
def generate_datetime():
    end_date = datetime(2023, 11, 7)
    random_days = random.randint(0, (end_date - datetime(1900, 1, 1)).days)
    random_time = random.randint(0, 86399)  # Random seconds within a day
    random_datetime = datetime(1900, 1, 1) + timedelta(days=random_days, seconds=random_time)
    return random_datetime


# Create a connection to your MySQL database
connection = mysql.connector.connect(
    host="localhost",  # Your database host
    user="root",  # Your MySQL username
    password="",  # Your MySQL password
    database="student register"  # Your database name
)

# Create a cursor
cursor = connection.cursor()

# Generate and insert 200 entries
for _ in range(1000):
    uid = generate_uid()
    name = ''.join(random.choices(string.ascii_letters, k=10))
    regno = generate_regno()
    chkin = random.choice([True, False])
    dt = generate_datetime()
    
    # Insert the data into the database
    sql = "INSERT INTO students (UID, Name, RegNo, Chkin, DT) VALUES (%s, %s, %s, %s, %s)"
    values = (uid, name, regno, chkin, dt)
    cursor.execute(sql, values)

# Commit the changes and close the cursor and connection
connection.commit()
cursor.close()
connection.close()
