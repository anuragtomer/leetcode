import random
import sqlite3

def main():
    val = 1 
    while val != 0:
        print('0. Exit')
        print('1. Next due question for today')
        print('2. Add a new question')
        print('3. Delete question')
        print('4. Print all questions')
        val = int(input("Your choice:"))
        if val == 0:
            exit(0)
        elif val == 1:
            pickQuestionPastDue()
        elif val == 2:
            addQuestion()
        elif val == 3:
            deleteQuestion()
        elif val == 4:
            printQuestions()
        else:
            print('Please give proper input.')

def printQuestions():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    for row in cur.execute('''SELECT * from questions'''):
        print(row)
    con.close()

def deleteQuestion():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    link = input('Link: ')
    deletequery = "DELETE FROM questions where link='" + link + "'"
    print(deletequery)
    try:
        cur.execute(deletequery)
        con.commit()
    except:
       print("No such link in db")
    con.close()

def addQuestion():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    name = input('Name: ')
    link = input('Link: ')
    print("Inserting " + name + ", " + link + " in database")
    try:
        cur.execute('''insert into questions(NAME, LINK, DUEDATE) values (?, ?, datetime('now', '+3 days'))''', (name, link))
        con.commit()
    except sqlite3.IntegrityError as err:
        print("Link already present")
    con.close()

def pickQuestionPastDue():
    dueQuestions = []
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    for row in cur.execute('''select * from questions where duedate < datetime('now')'''):
        dueQuestions.append(row)
    if len(dueQuestions) == 0:
        print('No questions due for today. Enjoy')
        con.close()
        return
    print("Number of questions past due: " + str(len(dueQuestions)))
    line = random.choice(dueQuestions)
    print("Question: " + line[1])
    days = input('When should this be reminded again? ')
    updatequery = "UPDATE questions SET duedate = datetime('now', '+"+str(days)+" days') where link='"+line[1]+"'"
    try:
        cur.execute(updatequery)
        con.commit()
    except:
        print('Something wrong in updating next due date')
    con.close()

if __name__ == '__main__':
    main()
