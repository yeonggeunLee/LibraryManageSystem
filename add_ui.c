
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[10];
};
static const struct sqlcxp sqlfpn =
{
    9,
    "add_ui.pc"
};


static unsigned int sqlctx = 35091;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,0,0,0,27,146,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,17,325,0,0,1,1,0,1,0,1,97,0,0,
55,0,0,2,0,0,45,331,0,0,0,0,0,1,0,
70,0,0,2,0,0,13,340,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
101,0,0,2,0,0,15,369,0,0,0,0,0,1,0,
};


// win32 Visual C 컴파일시 추가
// 프로그램 가장 첫 줄에 추가할 것
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>

void sql_error(char *msg) ;


void DB_connect();
void signup();
void login();
void searchbook();
void searchbook_resultlist();
void bookdetail();
void mypage();
void mypage_loanlist();

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

	/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 



// win32 Visual C 컴파일시 추가
#define getch() _getch()


void print_screen(char fname[]);

int login_state;
char keyword[10];



void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct UserInfo {
    char id[20];
    char name[20];
    char birth[20];
    char type[10];
};

struct UserInfo user;

struct BookInfo {
    char number[20];
    char title[20];
    char author[20];
    char publisher[20];
};

struct BookInfo book;

void clearLine(int x, int y, int length) {
    gotoxy(x, y);
    for (int i = 0; i < length; ++i) {
        printf(" ");
    }
}

int main() {
    _putenv("NLS_LANG=American_America.KO16KSC5601");
    DB_connect();

    char op[20];

    login_state = 0;
    while (1) {
        if (login_state == 0) {
            system("cls");
            print_screen("guest_main.txt");

            gotoxy(2, 20);
            fgets(op, sizeof(op), stdin);
            op[strcspn(op, "\n")] = '\0';


            if ((strcmp(op, "1") == 0)) {
                searchbook();
            }
            if ((strcmp(op, "2") == 0)) {
                login();
            }
            if ((strcmp(op, "3") == 0)) {
                signup();
            }
            if ((strcmp(op, "0") == 0)) {
                
                break;
            }
        }
        else if (login_state == 1) {
            system("cls");
            print_screen("member_main.txt");

            gotoxy(2, 20);
            fgets(op, sizeof(op), stdin);
            op[strcspn(op, "\n")] = '\0';

            if ((strcmp(op, "1") == 0)) {
                searchbook();
            }
            if ((strcmp(op, "2") == 0)) {
                mypage();
            }
            if ((strcmp(op, "3") == 0)) {
                memset(&user, 0, sizeof(user));
                login_state = 0;
                MessageBox(NULL, L"로그아웃을 완료하였습니다.", L"오류", MB_OK | MB_ICONINFORMATION);
            }
        }
    }
    
    
    return 0;
}

void DB_connect()
{
   /* 본인 계정이름으로 바꾸어 쓸 것 */
   strcpy((char *)uid.arr,"b20212952@//sedb.deu.ac.kr:1521/orcl");
   uid.len = (short) strlen((char *)uid.arr);
   /* 본인 계정 암호로 바꾸어 쓸 것 */
   strcpy((char *)pwd.arr,"20212952");
   pwd.len = (short) strlen((char *)pwd.arr);

   /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )5;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)&uid;
   sqlstm.sqhstl[0] = (unsigned int  )82;
   sqlstm.sqhsts[0] = (         int  )82;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&pwd;
   sqlstm.sqhstl[1] = (unsigned int  )22;
   sqlstm.sqhsts[1] = (         int  )22;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlstm.sqlcmax = (unsigned int )100;
   sqlstm.sqlcmin = (unsigned int )2;
   sqlstm.sqlcincr = (unsigned int )1;
   sqlstm.sqlctimeout = (unsigned int )0;
   sqlstm.sqlcnowait = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	// connection이 실패했을경우의 처리부분

	if (sqlca.sqlcode != 0 && sqlca.sqlcode != -1405){ 
		printf("\7Connect error: %s", sqlca.sqlerrm.sqlerrmc);
		getch();
		exit(-1);
	}

    printf("Oracle Connect SUCCESS by %s\n", uid.arr);

}

void signup() {
    system("cls");
    print_screen("guest_signup.txt");

    while (1) {

        while (1) {
            clearLine(45, 7, 10);
            gotoxy(45, 7);

            fgets(user.id, sizeof(user.id), stdin);
            user.id[strcspn(user.id, "\n")] = '\0';

            if (strcmp(user.id, "\0") == 0) {
                MessageBox(NULL, L"학번을 입력해 주세요.", L"알림", MB_OK | MB_ICONINFORMATION);

                continue;
            }
            else {
                break;
            }
        }

        while (1) {
            clearLine(45, 10, 10);
            gotoxy(45, 10);

            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            if (strcmp(user.name, "\0") == 0) {
                MessageBox(NULL, L"이름을 입력해 주세요.", L"알림", MB_OK | MB_ICONINFORMATION);

                continue;
            }
            else {
                break;
            }
        }

        while (1) {
            clearLine(45, 13, 10);
            gotoxy(45, 13);

            fgets(user.birth, sizeof(user.birth), stdin);
            user.birth[strcspn(user.birth, "\n")] = '\0';

            if (strcmp(user.birth, "\0") == 0) {
                MessageBox(NULL, L"생년월일을 입력해 주세요.", L"알림", MB_OK | MB_ICONINFORMATION);

                continue;
            }
            else {
                break;
            }
        }

        if (user.id == "1234") {
            MessageBox(NULL, L"이미 가입된 학번입니다.", L"알림", MB_OK | MB_ICONINFORMATION);
            continue;
        }
        else {
            MessageBox(NULL, L"회원가입 완료", L"알림", MB_OK | MB_ICONINFORMATION);
            break;
        }

    }
}


/*여기에 로그인 성공 시 logdata에 현재 로그인된 아이디 테이블 튜플들 전부 삭제하고 insert하기*/
void login() {
    system("cls");
    print_screen("guest_login.txt");

    char id[20];
    char name[20];
        strcpy(user.id, id);
        strcpy(user.name, name);

    while (1) {
        clearLine(42, 8, 13);
        gotoxy(43, 8);

        gets(id);

        clearLine(42, 11, 13);
        gotoxy(43, 11);

        gets(name);


        if ((strcmp(id, "1234") == 0 && (strcmp(name, "yg") == 0)) || (strcmp(user.id, id) == 0 && (strcmp(user.name, id) == 0))) {
            MessageBox(NULL, L"로그인 완료", L"알림", MB_OK | MB_ICONINFORMATION);
            strcpy(user.id, id);
            strcpy(user.name, name);
            
            login_state = 1;

            break;

        }
        else {
            MessageBox(NULL, L"로그인 아이디 또는 비번이 맞지 않습니다.", L"알림", MB_OK | MB_ICONINFORMATION);
            continue;
        }

    }
}

void searchbook() {
    system("cls");
    print_screen("combined_searchbook.txt");

    while (1) {
        
        gotoxy(43, 7);

        gets(book.number);


        gotoxy(43, 9);

        gets(book.title);


        gotoxy(43, 11);

        gets(book.author);


        gotoxy(43, 13);

        gets(book.publisher);


        searchbook_resultlist();


    }
}

#define PAGE_NUM 8
void searchbook_resultlist() {
/*도서번호에 8만 넣고 뒤쪽에 보면 짤림*/
    char op[20];
    system("cls");
    print_screen("combined_searchbook_resultlist.txt");

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar v_book_number[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } v_book_number;

       /* varchar v_book_title[37]; */ 
struct { unsigned short len; unsigned char arr[37]; } v_book_title;

       /* varchar v_book_author[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } v_book_author;

       /* varchar v_book_publisher[12]; */ 
struct { unsigned short len; unsigned char arr[12]; } v_book_publisher;


       char dynstmt[1000];
    /* EXEC SQL END DECLARE SECTION; */ 


    int x, y, count = 0, i;

     /* Register sql_error() as the error handler. */
     //EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

     /* 실행시킬 SQL 문장*/
     sprintf(dynstmt, "SELECT book_number, book_title, book_author, book_publisher FROM books WHERE to_char(book_number) LIKE '%%%s%%' AND book_title LIKE '%%%s%%' AND book_author LIKE '%%%s%%' AND book_publisher LIKE '%%%s%%'", book.number, book.title, book.author, book.publisher);
     /* EXEC SQL PREPARE S FROM :dynstmt; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 4;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )36;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (         void  *)dynstmt;
     sqlstm.sqhstl[0] = (unsigned int  )1000;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         void  *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned int  )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   
     /* 커서 선언 */   
     /* EXEC SQL DECLARE c_cursor CURSOR FOR S ; */ 

  
     /* 커서 오픈 */
     /* EXEC SQL OPEN c_cursor; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 4;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )55;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.sqlpfmem = (unsigned int  )0;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



     /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

     
     x = 7;
     y = 7;

     for (;;)
     {
         /* EXEC SQL FETCH c_cursor INTO :v_book_number, :v_book_title, :v_book_author, :v_book_publisher; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 13;
         sqlstm.arrsiz = 4;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )70;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.sqlpfmem = (unsigned int  )0;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (           int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (         void  *)&v_book_number;
         sqlstm.sqhstl[0] = (unsigned int  )14;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         void  *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned int  )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (         void  *)&v_book_title;
         sqlstm.sqhstl[1] = (unsigned int  )39;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         void  *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned int  )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (         void  *)&v_book_author;
         sqlstm.sqhstl[2] = (unsigned int  )14;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         void  *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned int  )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (         void  *)&v_book_publisher;
         sqlstm.sqhstl[3] = (unsigned int  )14;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         void  *)0;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned int  )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqphsv = sqlstm.sqhstv;
         sqlstm.sqphsl = sqlstm.sqhstl;
         sqlstm.sqphss = sqlstm.sqhsts;
         sqlstm.sqpind = sqlstm.sqindv;
         sqlstm.sqpins = sqlstm.sqinds;
         sqlstm.sqparm = sqlstm.sqharm;
         sqlstm.sqparc = sqlstm.sqharc;
         sqlstm.sqpadto = sqlstm.sqadto;
         sqlstm.sqptdso = sqlstm.sqtdso;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode == 1403) break;
}



	v_book_number.arr[v_book_number.len] = '\0' ;
	v_book_title.arr[v_book_title.len] = '\0' ;
	v_book_author.arr[v_book_author.len] = '\0' ;
 	v_book_publisher.arr[v_book_publisher.len] = '\0' ;

            gotoxy(x, y);
            printf("%s %28s %19s %16s\n", v_book_number.arr, v_book_title.arr, v_book_author.arr, v_book_publisher.arr);
            y++;
            count++;

            if( count == PAGE_NUM){
                gotoxy(14,18);
	   printf("\n                                  hit any key\n");
	   count = 0;
	   getch();

            gotoxy(13, 7); //이전 화면 부분 클리어
            for(i= 0; i < PAGE_NUM; i++){
		printf("                                                          \n");
	   }

	   y = 7 ;
	}
     }
    gotoxy(11, 17);
    printf("                              (END)\n");
   
    /* EXEC SQL CLOSE c_cursor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "1") == 0)) {
        bookdetail();
            
    }
    if ((strcmp(op, "0") == 0)) {
        
    }
}


void bookdetail() {
    char op[20];

    if (user.type == "admin") {
        system("cls");
        print_screen("admin_bookdetail.txt");

        gotoxy(2, 20);
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';

        if ((strcmp(op, "1") == 0)) {
            //bookdetail_modify();

        }
        if ((strcmp(op, "2") == 0)) {
            // 도서 삭제 sql 구문

        }
        if ((strcmp(op, "3") == 0)) {
            //managebook_loan();

        }
        if ((strcmp(op, "4") == 0)) {
            //returnbook();

        }
        if ((strcmp(op, "0") == 0)) {
            

        }
    }
    if (login_state == 1) {
        system("cls");
        print_screen("member_bookdetail.txt");

        while (1) {
            clearLine(2, 20, 1);
            gotoxy(2, 20);
            fgets(op, sizeof(op), stdin);
            op[strcspn(op, "\n")] = '\0';

            if ((strcmp(op, "1") == 0)) {
                // 사용자 도서 대출 sql 구문
                printf("대출 실행");
            }
            if ((strcmp(op, "0") == 0)) {
                searchbook_resultlist();
                break;
            }
        }
    }
}

void mypage() {
    char op[20];
    system("cls");
    print_screen("member_mypage.txt");
/*
EXEC SQL BEGIN DECLARE SECTION;
   varchar v_user_number[12];
   varchar v_user_name[12];
   int v_user_loans;
   int v_user_overdue;

EXEC SQL END DECLARE SECTION;

    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");
   
    EXEC SQL SELECT users.user_number, users.user_name, users.user_loans, users.user_overdue
                    INTO :v_user_number, :v_user_name, :v_user_loans, :v_user_overdue
                  FROM users, logdata
                  WHERE users.user_number = logdata.current_login;

    v_user_number.arr[v_user_number.len] = '\0';
    v_user_name.arr[v_user_name.len] = '\0';

    gotoxy(7, 40);
    printf("%s", user.id);

    gotoxy(8, 40);
    printf("%s", user.name);

    gotoxy(9, 40);
    printf("%d", v_user_loans);

    gotoxy(10, 40);
    printf("%d", v_user_overdue);
*/
    gotoxy(2, 20);
    gets(op);

    if ((strcmp(op, "1") == 0)) {
        mypage_loanlist();
        
    }
    if ((strcmp(op, "0") == 0)) {

    }

}


void mypage_loanlist() {
    char op[20];
    system("cls");
    print_screen("member_mypage_loanlist.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "1") == 0)) {
        mypage_loanlist();

    }
}


void print_screen(char fname[])
{
    FILE* fp;
    char line[100];

    if ((fp = fopen(fname, "r")) == NULL) {
        printf("file open error\n");
        getch();
        exit(-1);
    }
    while (1)
    {
        if (fgets(line, 99, fp) == NULL) {
            break;
        }
        printf("%s", line);
    }

    fclose(fp);
}