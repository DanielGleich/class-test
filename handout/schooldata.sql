-- SQLite Code
CREATE TABLE "student" (
	"id"					INTEGER NOT NULL,		-- id der Person
	"name"					TEXT NOT NULL,			-- Name der Person
	"vorname"				TEXT NOT NULL,			-- Vorname der Person
	PRIMARY KEY ( "id" )
);

CREATE TABLE "course" (
	"id"					INTEGER NOT NULL,		-- id vom Kurs
	"name"					TEXT NOT NULL,			-- Kursname	
	PRIMARY KEY ( "id" ) 
);

CREATE TABLE "zuoStudentCourse" (
	"studentId"				INTEGER NOT NULL, 		-- id der Person
	"courseId"				INTEGER NOT NULL,		-- id vom Kurs
	FOREIGN KEY ( "studentId" ) REFERENCES "student"( "id" ),
	FOREIGN KEY ( "courseId" ) 	REFERENCES "course"( "id" ),
	PRIMARY KEY ( "studentId", "courseId" ) 
);
											
--								ID, Name,			Vorname
INSERT INTO student VALUES 	(	 1,	'Müller',		'Klaus' );
INSERT INTO student VALUES 	(  	 2, 'Meier', 		'Ute' );
INSERT INTO student VALUES 	(  	 3, 'Antonidas', 	'Carolin' );
INSERT INTO student VALUES 	(  	 4, 'Berghaus', 	'Claus' );
INSERT INTO student VALUES 	(  	 5, 'Dörfer', 		'Marion' );
INSERT INTO student VALUES 	(  	 6, 'Schmalweg', 	'Harry' );
INSERT INTO student VALUES 	(  	 7, 'Müller', 		'Uta' );
INSERT INTO student VALUES 	(  	 8, 'Wegmeister', 	'Herbert' );
INSERT INTO student VALUES 	(  	 9, 'Stollenhausen','Herbert' );
INSERT INTO student VALUES 	( 	10, 'Schmidt', 		'Wolfgang' );
INSERT INTO student VALUES 	( 	11, 'Staundörfer', 	'Maria' );
INSERT INTO student VALUES 	( 	12, 'Wölkchen', 	'Heinz' );
INSERT INTO student VALUES 	( 	13, 'Walkes', 		'Otto' );
INSERT INTO student VALUES 	( 	14, 'Schweiger', 	'Till' );
INSERT INTO student VALUES 	( 	15, 'Horn', 		'Boris' );

--								ID, Name
INSERT INTO course VALUES 	(	 1,	"Deutsch" );
INSERT INTO course VALUES 	(	 2,	"Englisch" );
INSERT INTO course VALUES 	(	 3,	"Mathematik" );
INSERT INTO course VALUES 	(	 4,	"Software" );

--									student,		Course
INSERT INTO zuoStudentCourse VALUES	(	 1,		 1 );
INSERT INTO zuoStudentCourse VALUES	(	 1,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 2,		 1 );
INSERT INTO zuoStudentCourse VALUES	(	 2,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 2,		 4 );
INSERT INTO zuoStudentCourse VALUES	(	 3,		 2 );
INSERT INTO zuoStudentCourse VALUES	(	 3,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 3,		 4 );
INSERT INTO zuoStudentCourse VALUES	(	 3,		 1 );
INSERT INTO zuoStudentCourse VALUES	(	 4,		 1 );
INSERT INTO zuoStudentCourse VALUES	(	 4,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 7,		 1 );
INSERT INTO zuoStudentCourse VALUES	(	 5,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 5,		 4 );
INSERT INTO zuoStudentCourse VALUES	(	 6,		 2 );
INSERT INTO zuoStudentCourse VALUES	(	 6,		 3 );
INSERT INTO zuoStudentCourse VALUES	(	 6,		 4 );




