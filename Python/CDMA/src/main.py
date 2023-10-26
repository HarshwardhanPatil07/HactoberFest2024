'''MAIN Module for implementing all functionaties by threading and multiprocessing'''

import const
import threading
import multiprocessing
from sender import Sender
from channel import Channel
from receiver import Receiver


def get_next_powerof2(num):
    '''returns next integer of n which is a power of 2'''
    power = 1
    while power < num: power *= 2
    return power


def build_walsh_table(length, i1, i2, j1, j2, is_complement):
    '''Walsh code encoder function'''
    if length == 2:
        if not is_complement:
            wls_table[i1][j1] = 1
            wls_table[i1][j2] = 1
            wls_table[i2][j1] = 1
            wls_table[i2][j2] = -1
        else:
            wls_table[i1][j1] = -1
            wls_table[i1][j2] = -1
            wls_table[i2][j1] = -1
            wls_table[i2][j2] = 1

        return

    midi = (i1+i2)//2
    midj = (j1+j2)//2

    build_walsh_table(length/2, i1, midi, j1, midj, is_complement)
    build_walsh_table(length/2, i1, midi, midj+1, j2, is_complement)
    build_walsh_table(length/2, midi+1, i2, j1, midj, is_complement)
    build_walsh_table(length/2, midi+1, i2, midj+1, j2, not is_complement)

    return


def start_simulation(table):
    '''Starts simulating the whole project'''

    write_from_channel_to_receiver = []
    read_from_channel_to_receiver = []


    ######################################################################################
    # Pipe() returns a tuple (of two objects) whose 1st-one can read and 2nd-one can write
    ######################################################################################
    for _ in range(const.total_receiver_number):
        read_head, write_head = multiprocessing.Pipe()
        read_from_channel_to_receiver.append(read_head)     # goes to receiver
        write_from_channel_to_receiver.append(write_head)   # goes to channel

    read_from_sender_to_channel, write_from_sender_to_channel = multiprocessing.Pipe()


    ######################################################################################
    # initialise the sender list, receiver list, sender threadlist and receiver threadlist
    ######################################################################################
    sender_list = []
    receiver_list = []
    sender_threads = []
    receiver_threads = []


    ##############################################################
    # creating the channel, sender and receiver classes' instances
    ##############################################################
    channel = Channel(0, read_from_sender_to_channel, write_from_channel_to_receiver)

    for i in range(const.total_sender_number):
        sender = Sender(i, table[i], write_from_sender_to_channel)
        sender_list.append(sender)

    for i in range(const.total_receiver_number):
        receiver = Receiver(i, table, read_from_channel_to_receiver[i])
        receiver_list.append(receiver)


    ########################################################################################
    # making one channel thread, and multiple sender-receiver threads, and add them to lists
    ########################################################################################
    channel_thread = threading.Thread(name="Channel-Thread", target=channel.start_channel)

    for i in range(len(sender_list)):
        s = threading.Thread(name="Sender-Thread" + str(i+1), target=sender_list[i].start_sender)
        sender_threads.append(s)

    for i in range(len(receiver_list)):
        r = threading.Thread(name="Receiver-Thread"+str(i+1), target=receiver_list[i].start_receiver)
        receiver_threads.append(r)


    #############################################################################################
    # MULTIPROCESSING STARTS HERE
    # initialise and end execution of single channel thread, and multiple sender-receiver threads
    #############################################################################################
    channel_thread.start()

    for thread in receiver_threads:
        thread.start()

    for thread in sender_threads:
        thread.start()

    for thread in sender_threads:
        thread.join()

    for thread in receiver_threads:
        thread.join()

    channel_thread.join()



if __name__ == "__main__":

    NUM = get_next_powerof2(const.total_sender_number)
    wls_table = [[0 for _ in range(NUM)] for _ in range(NUM)]

    if const.total_sender_number <= 1: wls_table = [1]
    else: build_walsh_table(NUM, 0, NUM - 1, 0, NUM - 1, False)

    with open('textfiles/logfile.txt', 'a+', encoding='utf-8') as fptr:
        fptr.write("\n\n------------------------------------------------------------------------------------\n\tWALSH TABLE : {}\
        \n------------------------------------------------------------------------------------\n\n".format(str(wls_table)))

    print("\n\n------------------------------------------------------------------------------------\n\tWALSH TABLE : {}\
        \n------------------------------------------------------------------------------------\n\n".format(str(wls_table)))

    start_simulation(wls_table)
