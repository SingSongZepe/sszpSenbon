from dataclasses import dataclass

@dataclass
class BookInfo:
    href: str
    cover: str
    title: str
    publisher: str
    authors: str
    file_info: str
    language: str
    rating: str
    