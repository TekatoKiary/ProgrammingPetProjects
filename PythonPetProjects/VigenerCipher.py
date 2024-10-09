class VigenerCipher:
    key = "a"
    key_index = 0

    def __init__(self, key: str = "a"):
        self.set_key(key)

    def set_key(self, value: str) -> None:
        self.key_index = 0
        self.key = ""
        for i in value:
            if 'z' >= i.lower() >= 'a':
                self.key += i
        if self.key == "":
            self.key = "a"

    def __getDecodingChar(self, value: str) -> str:
        if (len(value) != 1):
            raise ValueError
        if 'z' >= value >= 'a':
            return self.__to_lower_ascii((self.__to_index_in_alphabet(self.__get_next_key_char()) +
                                         self.__to_index_in_alphabet(value)) % self.__get_alphabets_length())
        if 'Z' >= value >= 'A':
            return self.__to_upper_ascii((self.__to_index_in_alphabet(self.__get_next_key_char()) +
                                         self.__to_index_in_alphabet(value)) % self.__get_alphabets_length())
        return value

    def decode(self, value: str) -> str:
        result = str()
        for i in value:
            result += self.__getDecodingChar(i)
        return result

    def __get_alphabets_length(self) -> int:
        return ord('z') - ord('a') + 1

    def __get_next_key_char(self) -> str:
        value = self.key[self.key_index]
        self.key_index = (self.key_index + 1) % len(self.key)
        return value

    def __to_index_in_alphabet(self, value: str) -> int:
        if (len(value) != 1):
            raise ValueError
        return ord(value.lower()) - ord('a')

    def __to_lower_ascii(self, value: int) -> str:
        return chr(value + ord('a'))

    def __to_upper_ascii(self, value: int) -> str:
        return chr(value + ord('A'))


vigener = VigenerCipher(input("Введите ключ: "))
value = input("Введите строку или \"exit\", если хотите закончить программу: ")
while value != "exit":
    print(vigener.decode(value))
    value = input("Введите строку или \"exit\", если хотите закончить программу: ")

