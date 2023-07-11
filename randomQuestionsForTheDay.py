import random
import os
import sqlite3

DBFILE = '/Users/anurag/leetcode/questions.db'


def main():
    val = 1
    while val != 0:
        print('\n0. Exit')
        print('1. Next due question for today')
        print('2. Add a new question')
        print('3. Delete question')
        print('4. Print all questions')
        print('5. Total number of questions')
        print('6. Search question')
        print('7. Questions done today')
        print('8. Questions done in last 7 days')
        print('9. Total questions past due')
        try:
            val = int(input("Your choice: ") or "2")
            if val == 0:
                os.system("git add questions.db")
                exit(0)
            elif val == 1:
                pickQuestionPastDue()
            elif val == 2:
                addQuestion()
            elif val == 3:
                deleteQuestion()
            elif val == 4:
                printQuestions()
            elif val == 5:
                printQuestionCounts()
            elif val == 6:
                searchQuestion()
            elif val == 7:
                questionsDoneToday()
            elif val == 8:
                questionsDoneInLastSevenDays()
            elif val == 9:
                questionsPastDue()
            elif val == 42:
                print(
                    "Oh.. You know secret option. Fine, go ahead and change due.")
                changeDueDate()
            else:
                print('Choose wisely!!')
        except:
            print('Invalid input. Quitting')
            os.system("git add questions.db")
            exit(0)


def questionsPastDue():
    dueQuestions = []
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    for row in cur.execute(
            '''SELECT * FROM questions WHERE duedate < datetime('now', 'start of day')'''):
        dueQuestions.append(row)
    if len(dueQuestions) == 0:
        print('No questions due for today. Enjoy')
        con.close()
        return
    print("Number of questions past due: " + str(len(dueQuestions)))
    con.close()


def pickQuestionPastDue():
    print('1. Medium')
    print('2. Hard')
    val = int(input("Choice? ") or "2")
    difficulty = 'HARD'
    if val == 1:
        difficulty = 'MEDIUM'
    dueQuestions = []
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    for row in cur.execute(
            '''SELECT * FROM questions WHERE duedate < datetime('now', 'start of day') AND DIFFICULTY IN ("'''
            + difficulty + '''")'''):
        dueQuestions.append(row)
    if len(dueQuestions) == 0:
        print('No questions due for today. Enjoy')
        con.close()
        return
    print("Number of questions past due: " + str(len(dueQuestions)))
    line = random.choice(dueQuestions)
    print("Question: " + line[1])
    days = input('When should this be reminded again? ')
    updatequery = "UPDATE questions SET duedate = datetime('now', '+" + str(
        days) + " days', 'start of day'), practice_count = " + str(
            int(line[6]) + 1
        ) + ", last_revision = datetime('now', 'start of day') WHERE link='" + line[1] + "'"
    try:
        cur.execute(updatequery)
        con.commit()
    except:
        print('Something wrong in updating next due date')
    con.close()


def addQuestion():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    link = input('Link: ')
    if link[-1] != '/':
        link = link + '/'

    query = "SELECT * FROM questions where link='" + link + "'"
    found = False
    question_row = iter
    update_query = ""
    for row in cur.execute(query):
        question_row = row
        found = True
        break
    if found:
        days = int(input('When should this be reminded next? ') or '0')
        update_query = "UPDATE questions SET DUEDATE = datetime('now', '+" + str(
            days) + " days', 'start of day'), PRACTICE_COUNT = " + str(
                int(question_row[6]) + 1
            ) + ", LAST_REVISION = datetime('now', 'start of day') WHERE link='" + link + "'"

    else:
        name = input('Name: ')
        difficulty = input('Difficulty: ')
        company = input('Company: ') or 'NA'
        update_query = "INSERT INTO questions(NAME, LINK, DUEDATE, TODAY, DIFFICULTY, COMPANY, PRACTICE_COUNT, LAST_REVISION) VALUES ('"+name+"', '"+link+"', datetime('now', '+3 days', 'start of day'), datetime('now', 'start of day'), '"+difficulty.upper()+"', '"+company.upper()+"', 1, datetime('now', 'start of day'))"
    try:
        print(update_query)
        cur.execute(update_query)
        con.commit()
    except sqlite3.IntegrityError:
        print('Something wrong in putting questions into DB.')
    con.close()


def deleteQuestion():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    link = input('Link: ')
    deletequery = "DELETE FROM questions WHERE link='" + link + "'"
    print(deletequery)
    try:
        cur.execute(deletequery)
        con.commit()
    except:
        print("No such link in db")
    con.close()


def printQuestions():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    print("\nAll questions in DB: ")
    i = 1
    for row in cur.execute('''SELECT * FROM questions'''):
        print(str(i) + '. ' + f'{row[0]:<45}' + " | " + row[1])
        i = i + 1
    con.close()


def printQuestionCounts():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    print("No of questions in DB: ", end='')
    for row in cur.execute('''SELECT COUNT(*) FROM questions'''):
        print(row[0])
    con.close()


def searchQuestion():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    print('Search By?')
    print('1. Name')
    print('2. Link')
    print('3. Company')
    print('4. Difficulty')
    val = int(input('?: '))
    print('Name | Link | Due Date | Enter Date | Difficulty | Company')
    if val == 1:
        name = input('Name: ')
        query = "Select * FROM questions where name='" + name + "'"
        print('Questions found with Name = ' + name + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1] + ' | ' + row[2] + ' | ' +
                  row[3] + ' | ' + row[4] + ' | ' + row[5])
    elif val == 2:
        link = input('Link: ')
        query = "SELECT * FROM questions where link='" + link + "'"
        print('Questions found with Link = ' + link + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1] + ' | ' + row[2] + ' | ' +
                  row[3] + ' | ' + row[4] + ' | ' + row[5])
    elif val == 3:
        company = input('Company: ')
        query = "SELECT * FROM questions where company like '%" + company.upper(
        ) + "%'"
        print('Questions found with company = ' + company.upper() + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1] + ' | ' + row[2] + ' | ' +
                  row[3] + ' | ' + row[4] + ' | ' + row[5])
    elif val == 4:
        difficulty = input('Difficulty: ')
        query = "SELECT * FROM questions where difficulty='" + difficulty.upper(
        ) + "'"
        print('Questions found with difficulty = ' + difficulty.upper() + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1] + ' | ' + row[2] + ' | ' +
                  row[3] + ' | ' + row[4] + ' | ' + row[5])
    else:
        print('Wrong input.')
    con.close()


def questionsDoneToday():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    print(
        '\n               Name                               |                Link'
    )
    i = 1
    for row in cur.execute(
            '''SELECT * FROM questions WHERE LAST_REVISION >= datetime('now', 'start of day')'''
    ):
        print(str(i) + '. ' + f'{row[0]:<45}' + "  | " + row[1])
        i = i + 1
    con.close()


def questionsDoneInLastSevenDays():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    print(
        '\n               Name                               |                Link'
    )
    i = 1
    for row in cur.execute(
            '''SELECT * FROM questions WHERE LAST_REVISION >= datetime('now', '-7 days', 'start of day')'''
    ):
        print(str(i) + '. ' + f'{row[0]:<45}' + "  | " + row[1])
        i = i + 1
    con.close()


def changeDueDate():
    con = sqlite3.connect(DBFILE)
    cur = con.cursor()
    link = input('Link? ')
    query = "SELECT COUNT(*) FROM questions where link='" + link + "'"
    found = False
    print('Questions found with Link = ' + link + ': ')
    for row in cur.execute(query):
        found = True
        print(row[0] + ' | ' + row[1] + ' | ' + row[2] + ' | ' + row[3] +
              ' | ' + row[4] + ' | ' + row[5])
    if found:
        days = int(input('When should this be reminded next? ') or '0')
        cur.execute("UPDATE questions SET duedate = datetime('now', '+" +
                    str(days) + " days', 'start of day') WHERE link='" + link + "'")
    cur.close()


if __name__ == '__main__':
    main()
