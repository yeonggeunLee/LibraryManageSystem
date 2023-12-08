/*2. 도서관 이용자 (회원)*/
/*2.2 자신의 정보 확인 Read*/
SELECT users.user_number, users.user_name
FROM users JOIN logdata
ON users.user_number = logdata.current_login;

SELECT users.user_number, users.user_name
FROM users, logdata
WHERE users.user_number = logdata.current_login;


/*자신의 정보 수정 Update*/
/*트리거 사용하여 자동으로 current_login도 바꿔주기*/
UPDATE users
SET user_number = '9998', user_name = 'gdragon'
WHERE users.user_number = (SELECT current_login FROM logdata);
COMMIT;


/*자신의 계정 삭제 Delete*/
DELETE FROM users
WHERE user_number


/*2.5도서 검색 Read*/
/*도서 이름으로 검색*/
SELECT *
FROM books
WHERE book_title = '&å�̸�';

/*도서 번호로 검색*/
SELECT *
FROM books
WHERE book_number = '&������ȣ';

/*저자 이름으로 검색*/
SELECT *
FROM books
WHERE book_author = '&�����̸�';

/*출판사로 검색*/
SELECT *
FROM books
WHERE book_publisher = '&���ǻ�';

/*십진분류로 검색*/
/*와일드 카드 써서 검색*/

/*2.6 도서 대출 Update*/



/*2.8 도서 예약 Update*/



/*2.9 자신의 대출 목록 및 예약 목록 확인 Read*/



