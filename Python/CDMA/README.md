# CDMA

* To simulate the project properly-

    1. Change values of variables in ```const.py``` according to your wish. (Specially ```total_sender_number``` and ```total_receiver_number```).\
    Make sure that ```total_sender_number``` = ```total_receiver_number``` = some integer (preferebly of size 2^n, i.e., 2, 4, 8, 16,...).

    2. You need to create as many number of input files in ```./src/textfiles/input/``` as the integer value you store in ```total_sender_number```\
     in ```const.py```, for that ```gen_file.py``` script will help, if ```total_sender_number``` > **number of input files**, the program may \
     throw exceptions and desired results may not show up.

    3. Now make sure you're in the ```./src``` folder and run ```python3 main.py``` in the terminal **after deleting the\
    ```./src/textfiles/logfile.txt```, ```./src/textfiles/analysis.txt``` and ```output.txt``` files from ```.src/textfiles/output/``` folder**.

    4. Keep track of the live changes made on the newly generated ```analysis.txt``` and ```logfile.txt```.

    5. Press ```ctrl+c``` twice to stop the simulation.
