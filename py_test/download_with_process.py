from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QProgressBar, QLabel
from PySide6.QtCore import Qt, QThread, Signal
from urllib.parse import urljoin as uj
import requests
import time

zlibrary_root_url = 'https://zh.z-library.se/'

class DownloadThread(QThread):
    progress_update = Signal(int, str)  # Signal for updating progress bar and speed label

    def __init__(self, url, headers):
        super().__init__()
        self.url = url
        self.headers = headers
        self.verify = False

    def run(self):
        response = requests.get(self.url, stream=True, headers=self.headers, verify=self.verify)
        total_size = int(response.headers.get('content-length', 0))
        bytes_downloaded = 0
        start_time = time.time()

        with open('df', 'wb') as file:
            for chunk in response.iter_content(chunk_size=1024):
                if chunk:
                    file.write(chunk)
                    bytes_downloaded += len(chunk)
                    elapsed_time = time.time() - start_time
                    download_speed = bytes_downloaded / (1024 * elapsed_time)  # Speed in KB/s
                    progress = int(bytes_downloaded / total_size * 100)
                    self.progress_update.emit(progress, f'{download_speed:.2f} KB/s')

class DownloadWidget(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

        self.href = '/dl/17803802/83817d'
        self.cookie = 'remix_userkey=cc2fc3be66f040b2b0a3d1e3b13e41eb; remix_userid=27359678; '
        self.headers = {
            'cookie': self.cookie,
        }
        self.download_url = uj(zlibrary_root_url, self.href)

    def initUI(self):
        self.setWindowTitle('Download Widget')
        layout = QVBoxLayout()

        self.progress_bar = QProgressBar()
        self.progress_label = QLabel()
        self.download_button = QPushButton('Start Download')

        layout.addWidget(self.progress_bar)
        layout.addWidget(self.progress_label)
        layout.addWidget(self.download_button)

        self.setLayout(layout)

        self.download_button.clicked.connect(self.start_download)

    def start_download(self):
        self.download_thread = DownloadThread(self.download_url, self.headers)
        self.download_thread.progress_update.connect(self.update_progress)
        self.download_thread.run()

    def update_progress(self, progress, speed):
        self.progress_bar.setValue(progress)
        self.progress_label.setText(f'Download Speed: {speed}')

if __name__ == "__main__":
    app = QApplication([])

    download_widget = DownloadWidget()
    download_widget.show()

    app.exec()
