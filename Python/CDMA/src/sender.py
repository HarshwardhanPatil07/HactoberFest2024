'''Sender Module for walsh encoded data sending'''

import sys
import time
import const
import threading
from datetime import datetime


class Sender:
    '''Sender Class to implement data sending functionalities'''

    def __init__(self, name, walsh_code, sender_to_channel):
        self.name               = name
        self.walsh_code         = walsh_code        # tuple containg walshCode
        self.sender_to_channel  = sender_to_channel # a multiprocessing pipe
        self.start              = 0
        self.bit_count          = 0
        self.total_delay        = 0


    def open_file(self, sender):
        '''Opens file in read mode and returns file-pointer-object'''
        try:
            file_name = const.input_file_path + 'input' + str(sender+1) + '.txt'
            fptr = open(file_name, 'r', encoding='utf-8')
        except FileNotFoundError as fnfe:
            curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
            print("{} EXCEPTION CAUGHT : {}".format(curr_datetime, str(fnfe)))
            sys.exit("File with name {} is not found!".format(file_name))
        return fptr


    def send_data(self):
        '''Sends data continuously'''
        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n{} ||| SENDER-{}     ||  STARTS SENDING TO RECEIVER-{}".format(curr_datetime, self.name+1, self.name+1))
        self.start = time.time()
        file = self.open_file(self.name)
        byte = file.read(const.default_data_packet_size)
        while byte:
            data = '{0:08b}'.format(ord(byte))      # send the data bits of byte
            for i in range(len(data)):
                data_to_send = []
                data_bit = int(data[i])
                if data_bit == 0: data_bit = -1
                for j in self.walsh_code:
                    data_to_send.append(j * data_bit)
                ##############################################
                self.sender_to_channel.send(data_to_send)
                ##############################################
                self.bit_count += 1
                curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
                with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
                    rep_file.write("\n{} ||| SENDER-{}     ||  DATA BIT SEND {}".format(curr_datetime, self.name+1, data_bit))
                ##############################################
                time.sleep(const.sender_sleep_time)
                ##############################################
            byte = file.read(const.default_data_packet_size)

            self.total_delay = round((time.time()-self.start), 2)

        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/analysis.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n\n********** {} SENDER-{} STATS **********\n".format(curr_datetime, self.name+1) + \
                            "--> {}-Sender System\n".format(const.total_sender_number) + \
                            "--> Total Bits Transferred: {}\n".format(self.bit_count) + \
                            "--> Total Time Taken: {} seconds\n".format(self.total_delay) + \
                            "--> Throughput: {} bps\n".format(round(self.bit_count/self.total_delay, 3)) + \
                            "********************************************************\n\n" + '\n')


        curr_datetime = datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as rep_file:
            rep_file.write("\n{} ||| SENDER-{}     ||  DONE SENDING...".format(curr_datetime, self.name+1))


    def start_sender(self):
        '''Initializes and terminates the sending thread'''
        sender_thread = threading.Thread(name="Sender-Thread" + str(self.name+1), target=self.send_data)     
        sender_thread.start()
        sender_thread.join()
