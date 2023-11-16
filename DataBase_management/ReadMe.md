# Student Register Database Setup

## Overview

This repository contains instructions for setting up the MySQL database for the "Student Register" project. The database is managed using XAMPP, a free and open-source cross-platform web server solution stack package developed by Apache Friends.

## Table of Contents

1. [Prerequisites](#prerequisites)
2. [Database Configuration](#database-configuration)
3. [Usage](#usage)

## Prerequisites

Before you begin, ensure you have XAMPP installed on your machine. You can download it from [here](https://www.apachefriends.org/index.html).

## Database Configuration

1. Launch the XAMPP control panel and start the MySQL server.

2. Open your web browser and go to `http://localhost/phpmyadmin`.

3. Log in to phpMyAdmin using the default credentials (username: `root`, password: `''`).

4. Create a new database named "student register":

   - Click on the "New" button in the left sidebar.
   - Enter "student register" as the database name and click "Create."

5. Select the newly created database from the left sidebar.

6. Create a new table in the DB called students with following columns :
    - `UID` (varchar(10))
    - `Name` (varchar(100))
    - `RegNo` (int(9))
    - `chkin` (tinyint(1))
    - `DT` (datetime)

    
    > **Note:** If you want to create a different SQL database architecture changes will be required in the following:
    1. PHP files
    2. DBConn library
    3. main code (adjust the way the system reacts to db read writes)

7. Use the db_filler.py to fill out the DB:
    - please make required changes in the python code to fit your needs.

## Usage

The "student_register" database includes a table named "students" with the following columns:

- `UID` (varchar(10))
- `Name` (varchar(100))
- `RegNo` (int(9))
- `chkin` (tinyint(1))
- `DT` (datetime)

Feel free to use these columns in your project to store student information. Modify your project's connection strings or any relevant configurations to interact with this database.
