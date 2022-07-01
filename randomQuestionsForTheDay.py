import random
import sqlite3

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
        val = int(input("Your choice: "))
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
        elif val == 5:
            printQuestionCounts()
        elif val == 6:
            searchQuestion()
        elif val == 7:
            questionsDoneToday()
        else:
            print('Please give proper input.')

def questionsDoneToday():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    print("No of questions done today: ", end='')
    for row in cur.execute('''SELECT COUNT(*) FROM questions where TODAY > datetime('now', 'start of day')'''):
        print(row[0])
    print('\n               Name                              |                Link')
    i=1
    for row in cur.execute('''SELECT * FROM questions WHERE TODAY > datetime('now', 'start of day')'''):
        print(str(i) +'. ' + f'{row[0]:<45}' + "  | " + row[1])
        i=i+1
    con.close()

def searchQuestion():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    print('Search By?')
    print('1. Name')
    print('2. Link')
    print('3. Company')
    print('4. Difficulty')
    val = int(input('?: '))
    if val == 1:
        name = input('Name: ')
        query = "Select * FROM questions where name='" + name + "'"
        print('Questions found with Name = ' + name + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1])
    elif val == 2:
        link = input('Link: ')
        query = "SELECT * FROM questions where link='" + link + "'"
        print('Questions found with Link = ' + link + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1])
    elif val == 3:
        company = input('Company: ')
        query = "SELECT * FROM questions where company like '%" + company.upper() + "%'"
        print('Questions found with company = ' + company.upper() + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1])
    elif val == 4:
        difficulty = input('Difficulty: ')
        query = "SELECT * FROM questions where difficulty='" + difficulty.upper() + "'"
        print('Questions found with difficulty = ' + difficulty.upper() + ': ')
        for row in cur.execute(query):
            print(f'{row[0]:<45}' + ' | ' + row[1])
    else:
        print('Wrong input.')
    con.close()

def printQuestionCounts():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    print("No of questions in DB: ", end='')
    for row in cur.execute('''SELECT COUNT(*) FROM questions'''):
        print(row[0])
    con.close()

def printQuestions():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    print("\nAll questions in DB: ")
    i = 1;
    for row in cur.execute('''SELECT * FROM questions'''):
        print(str(i) +'. ' + f'{row[0]:<45}' + " | " + row[1])
        i = i + 1
    con.close()

def deleteQuestion():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
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

def addQuestion():
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    name = input('Name: ')
    link = input('Link: ')
    difficulty = input('Difficulty: ')
    company = input('Company: ') or 'NA'
    try:
        cur.execute('''INSERT INTO questions(NAME, LINK, DUEDATE, TODAY, DIFFICULTY, COMPANY) VALUES (?, ?, datetime('now', '+3 days'), datetime('now'), ?, ?)''', (name, link, difficulty.upper(), company.upper()))
        con.commit()
    except sqlite3.IntegrityError as err:
        days = input("Link already present. When should this be reminded again? ")
        cur.execute("UPDATE questions SET duedate = datetime('now', '+"+str(days)+" days') WHERE link='"+link+"'")
        con.commit()
    con.close()

def pickQuestionPastDue():
    dueQuestions = []
    con = sqlite3.connect('/Volumes/GoogleDrive/My Drive/questions.db')
    cur = con.cursor()
    for row in cur.execute('''SELECT * FROM questions WHERE duedate < datetime('now')'''):
        dueQuestions.append(row)
    if len(dueQuestions) == 0:
        print('No questions due for today. Enjoy')
        con.close()
        return
    print("Number of questions past due: " + str(len(dueQuestions)))
    line = random.choice(dueQuestions)
    print("Question: " + line[1])
    days = input('When should this be reminded again? ')
    updatequery = "UPDATE questions SET duedate = datetime('now', '+"+str(days)+" days') WHERE link='"+line[1]+"'"
    try:
        cur.execute(updatequery)
        con.commit()
    except:
        print('Something wrong in updating next due date')
    con.close()

if __name__ == '__main__':
    main()
