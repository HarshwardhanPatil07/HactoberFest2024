#Username: TaeMochi12
#Aim: A KBC (Kaun Banega Crorepati) Game.
#Date: 17-10-2023

res = input("Shall we start our game of Kaun Banega Crorepati?(Y/N):")
questions = ["Question-1(Amount:5000):\nWhat is the capital of India?\nOptions:\nA.Puri\nB.New Delhi\nC.Meerut\nD.Chandigarh", "Question-2(Amount:10,000):\nWhich is the most popular K-Pop band in the world?\nOptions:\nA.StrayKidz\nB.Twice\nC.NewJeans\nD.BTS", "Question-3(Amount:50,000):\nWhich Indian movie is shown on South Korean television movie channels every sunday?\nOptions:\nA.Taare Zameen Par\nB.Dangal\nC.3 Idiots\nD.Kaabil",
             "Question-4(Amount:50,00,000):\nWho is the first indian K-Pop idol?\nOptions:\nA.Sriya Lenka\nB.Jessi\nC.Nancy\nD.Lisa", "Question-5(Amount:1 crore):\nWho is the singer of the song 'Our First Song'?\nOptions:\nA.Charlie Puth\nB.Halsey\nC.Joseph Vincent\nD.Justin Beiber"]

answers = [['b', 'B'], ['d', 'D'], ['c', 'C'], ['a', 'A'], ['c', 'C']]
congo = ['Wohoo Taliyaan!! YOU WON RS.5000', 'Waah Kya Baat Hai!! YOU WON RS.10,000', 'Taliyaan Rukni Nhi Chahiye! Adhbudh! YOU WON RS.50,000',
         'Boht Badhiyaa!! YOU WON RS.50,00,000,Agla Sawaal 1 crore k liye', 'AAP BAN GAYE HAIN CROREPATI!']
count = 0
if (res == 'Y' or res == 'y'):
    for q in questions:
        count = count+1
        print(q)
        ans = input("Which option would you like to lock?:")
        if (ans in answers[count-1]):
            print(congo[count-1])
        else:
            print("Wrong answer! Aapka humare sath safar bs yahi tak tha..")
            break
    print("Game Over!")
else:
    print("Okay Byee!")
