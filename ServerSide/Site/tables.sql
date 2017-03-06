-- Initial Tables for MVP, these will change.
-- Robert Curran 2016


CREATE TABLE Users ( UserID int unsigned auto_increment primary key, UserTokenHashed char(40) NOT NULL, Email varchar(150) UNIQUE NOT NULL , FirstName varchar(60) NOT NULL, SecondName varchar(60) NOT NULL, MobileNum char(40) NOT NULL , DateJoined timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP, LastLogin timestamp NOT NULL , AccessType int unsigned, MobileVerificationState  int unsigned  DEFAULT 0 ,MobileVerificationSentRequest  int unsigned  DEFAULT 0 );

CREATE TABLE LoginAttempts( AttemptID  int unsigned auto_increment Primary Key, AttemptedUserName varchar(250) NOT NULL , AttemptedAt timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP , LoginAttemptState  int unsigned  DEFAULT 0 );



CREATE TABLE Runs( RunID int unsigned primary key , CreatedAT timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP , RunTitle varchar(255) , RunDescription varchar(3000) );

-- Tempary way of doing this untl the data needed persist is more known!
CREATE TABLE RUNID_Run( DatumID int unsigned auto_increment primary key,  WallClock int unsigned NOT NULL , CreatedAT timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP , Opto0 int, Opto1 int, Opto2 int, Opto3 int, Opto4 int, Opto5 int, Opto6 int, Opto7 int, Opto8 int , WheelLAngSpeed int, WheelRAngSpeed int , MotorRSetPoint int, MotorLSetPoint int );

-- ROBOT
CREATE TABLE RobotState(contMode int unsigned DEFAULT 0 , manContDirID int unsigned DEFAULT 0 ) ;

-- Example data : user

-- This user being in a public repo should not be used for production :)
INSERT INTO Users (UserTokenHashed , Email, FirstName, SecondName, MobileNum, AccessType) VALUES( SHA1('greenEggs') , 'r@r.com' , 'Robert' , 'Curran' , '5555555' , 0  );