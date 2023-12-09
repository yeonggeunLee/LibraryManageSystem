#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void print_screen(char fname[]);

int login_state;
char keyword[10];

void signup();
void login();
void searchbook();
void searchbook_resultlist();
void bookdetail();
void mypage();
void mypage_loanlist();
void mypage_modify();
void managebook();
void bookdetail_modify();
void managebook_loan();
void searchmemeber();
void searchmember_resultlist();
void memberdetail();
void memberdetail_loanlist();
void memberdetail_modify();
void createbook();
void statistics();

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
    // DB_connect();

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
            if ((strcmp(op, "0") == 0)) {
                memset(&user, 0, sizeof(user));
                login_state = 0;
                MessageBox(NULL, L"�α׾ƿ��� �Ϸ��Ͽ����ϴ�.", L"����", MB_OK | MB_ICONINFORMATION);
            }
        }
        else if (login_state == 2) {
            system("cls");
            print_screen("admin_main.txt");

            gotoxy(2, 20);
            fgets(op, sizeof(op), stdin);
            op[strcspn(op, "\n")] = '\0';

            if ((strcmp(op, "1") == 0)) {
                searchbook();
            }
            if ((strcmp(op, "2") == 0)) {
                managebook();
            }
            if ((strcmp(op, "3") == 0)) {
                createbook();
            }
            if ((strcmp(op, "4") == 0)) {
                searchmemeber();
            }
            if ((strcmp(op, "5") == 0)) {
                statistics();
            }
            if ((strcmp(op, "0") == 0)) {
                memset(&user, 0, sizeof(user));
                login_state = 0;
                MessageBox(NULL, L"�α׾ƿ��� �Ϸ��Ͽ����ϴ�.", L"����", MB_OK | MB_ICONINFORMATION);
            }
        }
    }
    
    
    return 0;
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
                MessageBox(NULL, L"�й��� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

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
                MessageBox(NULL, L"�̸��� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

                continue;
            }
            else {
                break;
            }
        }

        

        if (user.id == "1234") {
            MessageBox(NULL, L"�̹� ���Ե� �й��Դϴ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
            continue;
        }
        else {
            MessageBox(NULL, L"ȸ������ �Ϸ�", L"�˸�", MB_OK | MB_ICONINFORMATION);
            break;
        }

    }
}

void login() {
    system("cls");
    print_screen("guest_login.txt");

    while (1) {
        clearLine(42, 8, 13);
        gotoxy(43, 8);

        fgets(user.id, sizeof(user.id), stdin);
        user.id[strcspn(user.id, "\n")] = '\0';

        clearLine(42, 11, 13);
        gotoxy(43, 11);

        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';

        if ((strcmp(user.id, "20213006") == 0 && (strcmp(user.name, "������") == 0)) || (strcmp(user.id, "1234") == 0 && (strcmp(user.name, "1234") == 0)) ||
            (strcmp(user.id, "admin") == 0 && (strcmp(user.name, "admin") == 0))) {
            MessageBox(NULL, L"�α��� �Ϸ�", L"�˸�", MB_OK | MB_ICONINFORMATION);
            
            if ((strcmp(user.id, "admin"))==0) {
                login_state = 2;
            }
            else {
                login_state = 1;
            }

            break;

        }
        else {
            MessageBox(NULL, L"�α��� ���̵� �Ǵ� ����� ���� �ʽ��ϴ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
            continue;
        }

    }
}

void searchbook() {
    system("cls");
    print_screen("combined_searchbook.txt");

    while (1) {
        
        gotoxy(43, 7);

        fgets(book.number, sizeof(book.number), stdin);
        book.number[strcspn(book.number, "\n")] = '\0';


        gotoxy(43, 9);

        fgets(book.title, sizeof(book.title), stdin);
        book.title[strcspn(book.title, "\n")] = '\0';


        gotoxy(43, 11);

        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0';


        gotoxy(43, 13);

        fgets(book.publisher, sizeof(book.publisher), stdin);
        book.publisher[strcspn(book.publisher, "\n")] = '\0';


        if (strcmp(book.number, "\0") == 0 && strcmp(book.title, "\0") == 0 &&
            strcmp(book.author, "\0") == 0 && strcmp(book.publisher, "\0") == 0) {
            MessageBox(NULL, L"Ű���带 �Է����ּ���", L"�˸�", MB_OK | MB_ICONINFORMATION);
            continue;
        }
        else {
            searchbook_resultlist();
            break;
        }

    }
}


void searchbook_resultlist() {
    char op[20];
    system("cls");
    print_screen("combined_searchbook_resultlist.txt");

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
    
    if (login_state == 2) {
        system("cls");
        print_screen("admin_bookdetail.txt");

        gotoxy(2, 20);
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';

        if ((strcmp(op, "1") == 0)) {
            bookdetail_modify();
            bookdetail();
        }
        if ((strcmp(op, "2") == 0)) {
            //sql ���� ���� ����

            //���� ���� �� ���� ������Ʈ
            MessageBox(NULL, L"���� ���� ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
            bookdetail();
        }
        if ((strcmp(op, "3") == 0)) {
            managebook_loan();
            bookdetail();
        }
        if ((strcmp(op, "4") == 0)) {
            //sql ���� �ݳ� ����

            MessageBox(NULL, L"���� �ݳ� ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
            bookdetail();
        }
        if ((strcmp(op, "0") == 0)) {
           
                
        }

    }
    if (login_state == 1) {
        system("cls");
        print_screen("member_bookdetail.txt");

        clearLine(2, 20, 1);
        gotoxy(2, 20);
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';

        if ((strcmp(op, "1") == 0)) {
            // ����� ���� ���� sql ����

            MessageBox(NULL, L"���� ���� ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
            bookdetail();
        }
        if ((strcmp(op, "0") == 0)) {
                
                
        }
    }
    
    
}


void mypage() {
    char op[20];
    system("cls");
    print_screen("member_mypage.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "1") == 0)) {
        mypage_loanlist();
        
    }
    if ((strcmp(op, "2") == 0)) {
        mypage_modify();

    }
    if ((strcmp(op, "3") == 0)) {
        //ȸ�� ���� ���� sql ����

        memset(&user, 0, sizeof(user));
        login_state = 0;
        MessageBox(NULL, L"ȸ�� ���� ���� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
        
        return;
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
        bookdetail();

    }
    
}

void mypage_modify() {
    char op[20];
    system("cls");
    print_screen("member_mypage_modify.txt");

    while (1) {
        gotoxy(45, 6);
        fgets(user.id, sizeof(user.id), stdin);
        user.id[strcspn(user.id, "\n")] = '\0';

        if (strcmp(user.id, "\0") == 0) {
            MessageBox(NULL, L"ȸ�� ��ȣ�� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 9);
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';

        if (strcmp(user.name, "\0") == 0) {
            MessageBox(NULL, L"ȸ�� �̸��� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    MessageBox(NULL, L"ȸ�� ���� ���� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
}

void managebook() {
    char op[20];
    system("cls");
    print_screen("admin_managebook.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    
    //�� ���� ��ȣ���ý� �ش� �� ������ �̵�
    if ((strcmp(op, "1") == 0)) {
        bookdetail();
    }
    
}

void bookdetail_modify() {

    char op[20];
    system("cls");
    print_screen("admin_bookdetail_modify.txt");

    while (1) {
        gotoxy(45, 6);
        fgets(book.number, sizeof(book.number), stdin);
        book.number[strcspn(book.number, "\n")] = '\0';

        if (strcmp(book.number, "\0") == 0) {
            MessageBox(NULL, L"���� ��ȣ�� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 8);
        fgets(book.title, sizeof(book.title), stdin);
        book.title[strcspn(book.title, "\n")] = '\0';

        if (strcmp(book.title, "\0") == 0) {
            MessageBox(NULL, L"���� ������ �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 10);
        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0';

        if (strcmp(user.id, "\0") == 0) {
            MessageBox(NULL, L"���� ���ڸ� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 12);
        fgets(book.publisher, sizeof(book.publisher), stdin);
        book.publisher[strcspn(book.publisher, "\n")] = '\0';

        if (strcmp(book.publisher, "\0") == 0) {
            MessageBox(NULL, L"���� ���ǻ縦 �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    MessageBox(NULL, L"���� ���� ���� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
}

void managebook_loan() {
    char id[20];
    system("cls");
    print_screen("admin_managebook_loan.txt");

    gotoxy(41, 13);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    if ((strcmp(id, "\0") == 0)) {
    }
    else {
        //���� ���� sql ó��


        MessageBox(NULL, L"���� ���� ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
        
    }
}

void searchmemeber() {
    system("cls");
    print_screen("admin_searchmember.txt");

    while (1) {

        gotoxy(43, 7);

        fgets(user.id, sizeof(user.id), stdin);
        user.id[strcspn(user.id, "\n")] = '\0';


        gotoxy(43, 9);

        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';


        gotoxy(43, 11);

        fgets(user.birth, sizeof(user.birth), stdin);
        user.birth[strcspn(user.birth, "\n")] = '\0';


        if (strcmp(user.id, "\0") == 0 && strcmp(user.name, "\0") == 0 && strcmp(user.birth, "\0") == 0) {
            MessageBox(NULL, L"Ű���带 �Է����ּ���", L"�˸�", MB_OK | MB_ICONINFORMATION);
            continue;
        }
        else {
            searchmember_resultlist();
            break;
        }

    }

}

void searchmember_resultlist() {
    char op[20];
    system("cls");
    print_screen("admin_searchmember_resultlist.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';


    //�� ȸ�� ��ȣ�� �´� 1~10���� ���� �Ҵ� �� memberdetail�� �̵�
    if ((strcmp(op, "1") == 0)) {
        memberdetail();

    }
    if ((strcmp(op, "0") == 0)) {

    }
}

void memberdetail() {
    char op[20];
    system("cls");
    print_screen("admin_memberdetail.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "1") == 0)) {
        memberdetail_loanlist();

    }
    if ((strcmp(op, "2") == 0)) {
        memberdetail_modify();

    }
    if ((strcmp(op, "3") == 0)) {
        //ȸ�� �ݳ� ó�� sql ����

        MessageBox(NULL, L"ȸ�� ���� �ݳ�ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
        memberdetail();

    }
    if ((strcmp(op, "4") == 0)) {
        //ȸ�� ���� ���� sql ����
        MessageBox(NULL, L"ȸ�� ���� ����ó�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
    }
    if ((strcmp(op, "0") == 0)) {
        searchmember_resultlist();

    }
}

void memberdetail_loanlist() {
    char op[20];
    system("cls");
    print_screen("admin_memberdetail_loanlist.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "1") == 0)) {
        bookdetail();

    }
}

void memberdetail_modify() {
    char op[20];
    system("cls");
    print_screen("admin_memberdetail_modify.txt");

    while (1) {
        gotoxy(45, 7);
        fgets(user.id, sizeof(user.id), stdin);
        user.id[strcspn(user.id, "\n")] = '\0';

        if (strcmp(user.id, "\0") == 0) {
            MessageBox(NULL, L"ȸ�� ��ȣ�� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 10);
        fgets(user.name, sizeof(user.name), stdin);
        user.name[strcspn(user.name, "\n")] = '\0';

        if (strcmp(user.name, "\0") == 0) {
            MessageBox(NULL, L"ȸ�� �̸��� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }
    MessageBox(NULL, L"ȸ�� ���� ���� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
}

void createbook() {
    char op[20];
    system("cls");
    print_screen("admin_createbook.txt");

    while (1) {
        gotoxy(45, 6);
        fgets(book.number, sizeof(book.number), stdin);
        book.number[strcspn(book.number, "\n")] = '\0';

        if (strcmp(book.number, "\0") == 0) {
            MessageBox(NULL, L"���� ��ȣ�� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 8);
        fgets(book.title, sizeof(book.title), stdin);
        book.title[strcspn(book.title, "\n")] = '\0';

        if (strcmp(book.title, "\0") == 0) {
            MessageBox(NULL, L"���� ������ �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 10);
        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0';

        if (strcmp(book.author, "\0") == 0) {
            MessageBox(NULL, L"���� ���ڸ� �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        gotoxy(45, 12);
        fgets(book.publisher, sizeof(book.publisher), stdin);
        book.publisher[strcspn(book.publisher, "\n")] = '\0';

        if (strcmp(book.publisher, "\0") == 0) {
            MessageBox(NULL, L"���� ���ǻ縦 �Է��� �ּ���.", L"�˸�", MB_OK | MB_ICONINFORMATION);

            continue;
        }
        else {
            break;
        }
    }

    MessageBox(NULL, L"���� �߰� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
}

void statistics() {

    char op[20];
    system("cls");
    print_screen("admin_statistics.txt");

    gotoxy(2, 20);
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';

    if ((strcmp(op, "\0") == 0)) {
        MessageBox(NULL, L"��� Ȯ�� �Ϸ�.", L"�˸�", MB_OK | MB_ICONINFORMATION);
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