#Author: Sumon Chatterjee @Sumon670
#Date: 13/10/2023
from PyQt5.QtWidgets import *
from PyQt5 import uic
import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

class GUI(QMainWindow):
    def __init__(self):
        super(GUI, self).__init__()
        uic.loadUi("mail.ui",self)
        self.show()
        self.pushButton.clicked.connect(self.signin)
        self.pushButton_2.clicked.connect(self.attachment)
        self.pushButton_3.clicked.connect(self.send)
        self.setWindowTitle("Mail Application using Python")

    def signin(self):
        print("Signing in...")
        try:
            self.server = smtplib.SMTP('smtp.gmail.com', 587)
            self.server.ehlo()
            self.server.starttls()
            self.server.ehlo()
            self.server.login(self.lineEdit.text(), self.lineEdit_2.text()) 
            self.lineEdit.setEnabled(False)
            self.lineEdit_2.setEnabled(False)
            self.pushButton.setEnabled(False)
            self.lineEdit_5.setEnabled(True)
            self.lineEdit_6.setEnabled(True)
            self.textEdit.setEnabled(True)
            self.pushButton_2.setEnabled(True)
            self.pushButton_3.setEnabled(True)
            self.msg = MIMEMultipart()
        except smtplib.SMTPAuthenticationError:
            print("ERROR:")
            msg_box = QMessageBox()
            msg_box.setText("Invalid credentials!!!")
            msg_box.exec()
        except:
            print("ERROR:")
            msg_box = QMessageBox()
            msg_box.setText("Login failed!!!")
            msg_box.exec()

    def attachment(self):
        print("Attachment...")
        options = QFileDialog.Options()
        filenames, _ = QFileDialog.getOpenFileNames(self, "Open File", "", "All Files (*.*)", options=options)
        if filenames != []:
            for filename in filenames:
                attachment = open(filename, "rb")
                filename = filename[filename.rfind("/") + 1:]
                p = MIMEBase('application', 'octet-stream')
                p.set_payload(attachment.read())
                encoders.encode_base64(p)
                p.add_header("Content-Disposition", f"attachment; filename={filename}")
                self.msg.attach(p)
                if not self.label_9.text().endswith(":"):
                    self.label_9.setText(self.label_9.text()+",")
                self.label_9.setText(self.label_9.text()+" "+filename)

    def send(self):
        print("Sending...")
        msg_box = QMessageBox()
        msg_box.setText("Do you want to send?")
        msg_box.addButton(QPushButton("Send"),QMessageBox.YesRole)
        msg_box.addButton(QPushButton("Don't Send"),QMessageBox.NoRole)

        if msg_box.exec() == 0:
            try:
                self.msg['From'] = self.lineEdit.text()
                self.msg['To'] = self.lineEdit_5.text()
                self.msg['Subject'] = self.lineEdit_6.text()
                self.msg.attach(MIMEText(self.textEdit.toPlainText(), 'plain'))
                content = self.msg.as_string()
                self.server.sendmail(self.lineEdit.text(), self.lineEdit_5.text(), content)
                msg_box = QMessageBox()
                msg_box.setText("Mail sent successfully!!")
                msg_box.exec()
            except:
                msg_box = QMessageBox()
                msg_box.setText("Sending failed!!!")
                msg_box.exec()
app = QApplication([])
win = GUI()
app.exec_()