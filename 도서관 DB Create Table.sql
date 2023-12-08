DROP TABLE users CASCADE CONSTRAINTS purge ;
DROP TABLE books CASCADE CONSTRAINTS purge ;
DROP TABLE logdata CASCADE CONSTRAINTS purge ;
DROP TABLE loan CASCADE CONSTRAINTS purge ;

--사용자 테이블
CREATE TABLE users (
    user_number VARCHAR2(10)
        CONSTRAINT users_user_number_pk PRIMARY KEY,
    user_name VARCHAR2(10)
        CONSTRAINT users_user_name_nn NOT NULL,
    user_loans INT DEFAULT 0
        CONSTRAINT users_user_loans_nn NOT NULL
        CONSTRAINT users_user_loans_ck CHECK(user_loans <= 3),
    user_overdue INT
        CONSTRAINT users_user_overdue_nn NOT NULL
);


--로그인 데이터 테이블
CREATE TABLE logdata (
    current_login VARCHAR2(10)
        CONSTRAINT logdata_current_login_pk PRIMARY KEY
);

select * from logdata;
select * from users;
select * from books;
insert into users values (4567,'gd', 1, 1);
commit;

select to_number(user_number) from users where user_number = 1234;


--도서 테이블
CREATE TABLE books (
    book_number VARCHAR2(10)
        CONSTRAINT books_book_number_pk PRIMARY KEY,
    book_title VARCHAR2(35)
        CONSTRAINT books_book_title_nn NOT NULL,
    book_author VARCHAR2(10)
        CONSTRAINT books_book_author_nn NOT NULL,
    book_publisher VARCHAR2(10)
        CONSTRAINT books_book_publisher_nn NOT NULL,
    book_code VARCHAR2(10)
        CONSTRAINT books_book_code_nn NOT NULL,
    book_loan_status VARCHAR2(10)
        CONSTRAINT books_book_loan_status_nn NOT NULL
);

/*
--도서 테스트 데이터 생성
SELECT * FROM books;
--총류
INSERT INTO books VALUES ('010001','도서학(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('010002','서지학(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('020001','문헌정보학(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('030001','백과사전(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('040001','강연집(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('040002','수필집(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('040003','연설문집(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('050001','일반연속간행물(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('060001','일반학회(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('060002','단체(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('060003','협회(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('060004','기관(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('070001','신문(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('070002','언론(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('070003','저널리즘(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('080001','일반전집(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('080002','총서(1권)', '김철수', 'A출판사', '000', '대출가능');
INSERT INTO books VALUES ('090001','향토자료(1권)', '김철수', 'A출판사', '000', '대출가능');
--100 철학
INSERT INTO books VALUES ('110001','형이상학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('120001','인식론(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('120002','인과론(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('120003','인간학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('130001','철학의체계(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('140001','경학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('150001','동양철학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('150002','사상(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('160001','서양철학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('170001','논리학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('180001','심리학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('190001','윤리학(1권)', '신짱구', 'B출판사', '100', '대출가능');
INSERT INTO books VALUES ('190002','도덕철학(1권)', '신짱구', 'B출판사', '100', '대출가능');
--200 종교
INSERT INTO books VALUES ('210001','비교종교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('220001','불교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('230001','기독교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('240001','도교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('250001','천도교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('260001','신도(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('270001','힌두교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('270002','브라만교(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('280001','이슬람교(회교)(1권)', '노진구', 'B출판사', '200', '대출가능');
INSERT INTO books VALUES ('290001','기타제종교(1권)', '노진구', 'B출판사', '200', '대출가능');
--300 사회과학
INSERT INTO books VALUES ('310001','통계학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('320001','경제학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('330001','사회학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('330002','사회문제(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('340001','정치학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('350001','행정학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('360001','법학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('370001','교육학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('380001','풍속(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('380002','예절(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('380003','민속학(1권)', '이대호', 'C출판사', '300', '대출가능');
INSERT INTO books VALUES ('390001','국방,군사학(1권)', '이대호', 'C출판사', '300', '대출가능');
--400 자연과학
INSERT INTO books VALUES ('410001','수학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('420001','물리학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('430001','화학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('440001','천문학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('450001','지학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('460001','광물학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('470001','생명과학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('480001','식물학(1권)', '장원삼', 'C출판사', '400', '대출가능');
INSERT INTO books VALUES ('490001','동물학(1권)', '장원삼', 'C출판사', '400', '대출가능');
--500 기술과학
INSERT INTO books VALUES ('510001','의학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('520001','농업,농학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('530001','공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('530002','공업일반(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('530003','토목공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('530004','환경공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('540001','건축공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('550001','기계학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('560001','전기공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('560002','전자공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('570001','화학공학(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('580001','제조업(1권)', '김성근', 'D출판사', '500', '대출가능');
INSERT INTO books VALUES ('590001','생활과학(1권)', '김성근', 'D출판사', '500', '대출가능');
--600 예술
INSERT INTO books VALUES ('610001','건축물(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('620001','조각예술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('620002','조형예술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('630001','공예미술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('630002','장식미술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('640001','서예(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('650001','회화(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('650002','도화(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('660001','사진예술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('670001','음악(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('680001','공연예술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('680002','매체예술(1권)', '정근우', 'D출판사', '600', '대출가능');
INSERT INTO books VALUES ('690001','오락,스포츠(1권)', '정근우', 'D출판사', '600', '대출가능');
--700 언어
INSERT INTO books VALUES ('710001','한국어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('720001','중국어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('730001','일본어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('730002','기타아시아제어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('740001','영어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('750001','독일어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('760001','프랑스어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('770001','스페인어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('770002','포르투갈어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('780001','이탈리아어(1권)', '박용택', 'Z출판사', '700', '대출가능');
INSERT INTO books VALUES ('790001','기타제어(1권)', '박용택', 'Z출판사', '700', '대출가능');
--800 문학
INSERT INTO books VALUES ('810001','한국문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('820001','중국문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('830001','일본문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('830002','기타아시아문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('840001','영미문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('850001','독일문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('860001','프랑스문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('870001','스페인문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('870002','포르투갈문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('880001','이탈리아문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
INSERT INTO books VALUES ('890001','기타제문학(1권)', '정현수', 'Z출판사', '800', '대출가능');
--900 역사
INSERT INTO books VALUES ('910001','아시아(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('920001','유럽(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('930001','아프리카(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('940001','북아메리카(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('950001','남아메리카(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('960001','오세아니아(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('970001','양극지방(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('980001','지리(1권)', '송승준', 'T출판사', '900', '대출가능');
INSERT INTO books VALUES ('990001','전기(1권)', '송승준', 'T출판사', '900', '대출가능');

COMMIT;
*/

/*대출 테이블*/
CREATE TABLE loan (
    book_number VARCHAR2(10)
        CONSTRAINT loan_book_number_fk REFERENCES BOOKS(book_number)
        CONSTRAINT loan_book_number_nn NOT NULL,
    user_number VARCHAR2(10)
        CONSTRAINT loan_user_number_fk REFERENCES USERS(user_number)
        CONSTRAINT loan_user_number_nn NOT NULL,
    book_loandate DATE
        CONSTRAINT loan_book_loandate_pk PRIMARY KEY,
    book_duedate DATE
        CONSTRAINT loan_book_duedate_nn NOT NULL,
    loan_status VARCHAR2(10)
        CONSTRAINT loan_loan_status_nn NOT NULL
);