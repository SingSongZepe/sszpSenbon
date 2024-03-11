from dataclasses import dataclass, asdict
import json

@dataclass
class BookFullInfo:
    cover: str
    url: str
    title: str
    authors: str
    rating: str
    description: str
    categories: str
    edition: str
    language: str
    isbn: str
    isbn10: str
    isbn13: str
    file: str
    volume: str
    year: str
    publisher: str
    pages: str
    series: str
    ipfs: str

    def transform_2json_str(self) -> str:
        return json.dumps(asdict(self))