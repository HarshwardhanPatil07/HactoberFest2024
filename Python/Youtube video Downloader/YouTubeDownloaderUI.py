import tkinter as tk
from tkinter import ttk
from pytube import YouTube
import threading
import os

class YouTubeDownloader:
    def __init__(self, root):
        self.root = root
        self.root.title("YouTube Video Downloader")

        self.create_widgets()

    def create_widgets(self):
        frame = ttk.Frame(self.root)
        frame.grid(row=0, column=0, padx=10, pady=10)

        url_label = ttk.Label(frame, text="Enter YouTube URL:")
        url_label.grid(row=0, column=0, sticky=tk.W)

        self.url_entry = ttk.Entry(frame, width=50)
        self.url_entry.grid(row=0, column=1, padx=5)

        quality_label = ttk.Label(frame, text="Select Quality:")
        quality_label.grid(row=1, column=0, sticky=tk.W)

        self.quality_var = tk.StringVar()
        self.quality_var.set("720p")

        self.quality_dropdown = ttk.Combobox(frame, textvariable=self.quality_var, values=["360p", "720p", "1080p"])
        self.quality_dropdown.grid(row=1, column=1, padx=5)

        download_button = ttk.Button(frame, text="Download", command=self.download_video)
        download_button.grid(row=2, columnspan=2, pady=10)

        self.progress_var = tk.DoubleVar()
        self.progress_bar = ttk.Progressbar(frame, variable=self.progress_var, maximum=100)
        self.progress_bar.grid(row=3, columnspan=2, padx=5, pady=5)

        self.result_label = ttk.Label(frame, text="")
        self.result_label.grid(row=4, columnspan=2)

    def download_video(self):
        url = self.url_entry.get()
        quality = self.quality_var.get()
        output_path = os.path.expanduser("~/Downloads/")  # Save in the user's home directory

        try:
            yt = YouTube(url)
            stream = yt.streams.filter(res=quality).first()
            download_thread = threading.Thread(target=self.start_download, args=(stream, output_path))
            download_thread.start()
        except Exception as e:
            self.result_label.config(text=f"Error: {str(e)}")

    def start_download(self, stream, output_path):
        try:
            stream.download(output_path)
            self.progress_var.set(100)
            self.result_label.config(text="Download complete!")
        except Exception as e:
            self.result_label.config(text=f"Error: {str(e)}")

