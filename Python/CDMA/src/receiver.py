'''Receiver Module for receiving encoded data and decoding'''

import sys
import const
import threading
from datetime import datetime

# curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
class Receiver:
    '''Receiver Class to receive sender sent encoded data and decode it to get the original data'''

    def __init__(self, name, wls_table, channel_to_receiver):
        self.name                 = name
        self.wls_table            = wls_table
        self.channel_to_receiver  = channel_to_receiver
        self.sender_to_receiver   = self.select_sender()
        self.code_length          = len(self.wls_table[0])


    def select_sender(self):
        '''Decodes which sender is sending which data'''
        return self.name


    def get_char(self, data):
        '''Receives character sent by sender'''
        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n\n{} ||| DATA : {}".format(curr_datetime, str(data)))
        summation = 0
        for i in range(8): summation += pow(2,i) * data[7-i]
        character = chr(summation)
        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n\n{} ||| CHAR RECEIVED : {}\n".format(curr_datetime, character))
        return character


    def open_file(self, sender):
        '''Opens output file and writes down decoded message'''
        try:
            file_name = const.output_file_path + 'output' + str(sender+1) + '.txt'
            fptr = open(file_name, 'a+', encoding='utf-8')
        except FileNotFoundError as fnfe:
            curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
            print("{} EXCEPTION CAUGHT : {}".format(curr_datetime, str(fnfe)))
            sys.exit("No file exists with name {} !".format(file_name))
        return fptr


    def receive_data(self):
        '''Receives Walsh encoded sender data and decodes it'''

        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n{} ||| RECEIVER-{}   ||  RECEIVES DATA FROM SENDER-{}".format(curr_datetime, self.name+1, self.sender_to_receiver+1))
        total_data = []
        while True:
            channel_data = self.channel_to_receiver.recv()

            # extract data
            summation = 0
            for i in range(len(channel_data)): summation += channel_data[i] * self.wls_table[self.sender_to_receiver][i]

            # extract data bit
            summation /= self.code_length
            if summation == 1: bit = 1
            elif summation == -1: bit = 0
            else: bit = -1

            curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
            with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
                rep_file.write("\n{} ||| RECEIVER-{}   ||  BIT RECEIVED : {}".format(curr_datetime, self.name+1, bit))

            if len(total_data) < 8 and bit != -1: total_data.append(bit)

            if len(total_data) == 8:
                character = self.get_char(total_data)
                output_file = self.open_file(self.sender_to_receiver)
                output_file.write(character)
                output_file.close()
                total_data = []


    def start_receiver(self):
        '''Initializes and terminates the receiver thread'''
        receiver_thread = threading.Thread(name='Receiver-Thread', target=self.receive_data)
        receiver_thread.start()
        receiver_thread.join()
