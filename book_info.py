from dataclasses import dataclass

@dataclass
class BookInfo:
    url: str
    cover: str
    title: str
    publisher: str
    authors: str
    file_info: str
    language: str
    rating: str
    