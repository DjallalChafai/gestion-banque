CREATE DATABASE IF NOT EXISTS 'bb'
CREATE DATABASE IF NOT EXISTS 'rv'
CREATE DATABASE IF NOT EXISTS 'n26'

USE 'bb';
DROP TABLE IF EXISTS 'info';
CREATE TABLE 'info' (
    'id' int NOT NULL,
    'firstname' varchar(30) DEFAULT NULL,
    'lastname' varchar(30) DEFAULT NULL,
    'address' varchar(30) DEFAULT NULL,
    'email' varchar(30) DEFAULT NULL,
    'phone' int DEFAULT NULL,
    'password' varchar(30) DEFAULT NULL,
    'account_number' int DEFAULT NULL,
    'balance' int DEFAULT NULL,
    PRIMARY KEY ('id'),
    UNIQUE KEY 'id' ('id')
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

USE 'rv';
DROP TABLE IF EXISTS 'info';
CREATE TABLE 'info' (
    'id' int NOT NULL,
    'firstname' varchar(30) DEFAULT NULL,
    'lastname' varchar(30) DEFAULT NULL,
    'address' varchar(30) DEFAULT NULL,
    'email' varchar(30) DEFAULT NULL,
    'phone' int DEFAULT NULL,
    'password' varchar(30) DEFAULT NULL,
    'account_number' int DEFAULT NULL,
    'balance' int DEFAULT NULL,
    PRIMARY KEY ('id'),
    UNIQUE KEY 'id' ('id')
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

USE 'n26';
DROP TABLE IF EXISTS 'info';
CREATE TABLE 'info' (
    'id' int NOT NULL,
    'firstname' varchar(30) DEFAULT NULL,
    'lastname' varchar(30) DEFAULT NULL,
    'address' varchar(30) DEFAULT NULL,
    'email' varchar(30) DEFAULT NULL,
    'phone' int DEFAULT NULL,
    'password' varchar(30) DEFAULT NULL,
    'account_number' int DEFAULT NULL,
    'balance' int DEFAULT NULL,
    PRIMARY KEY ('id'),
    UNIQUE KEY 'id' ('id')
) ENGINE=InnoDB DEFAULT CHARSET=utf8;