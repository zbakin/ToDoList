# TO DO list application

## Purpose
It is used to manage tasks, created by multiple users. Data is stored in the PostgresSQL db.
Database element is used only by 1 user at a time to update the task. 
Other user's requests will be stored in a buffer, until the DB resourse is available to be amended.

### Task
Each task consists of information such as:
* ID
* Name
* Due date
* Description
* Status

(Might need to add Author or Task owner)

## Installation

### Windows

### MacOS
brew install postgresql
brew install libpqxx

### Linux
sudo apt-get update -y
sudo apt install postgresql
sudo apt-get install -y libpqxx-dev
