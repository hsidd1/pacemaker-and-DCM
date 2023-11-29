"""Custom encryption class for assurance of data security

    Attributes:
        None

    Methods:
        encrypt: encrypts a string using a shift value
        decrypt: decrypts a string using a shift value

Yes, this is a class that only has static methods. This is because we want to be able to call the methods without having to create an instance of the class."""

class Encryption:
    @staticmethod
    def encrypt(text, shift):
        encrypted_text = ""
        for char in text:
            if char.isalpha():
                if char.isupper():
                    encrypted_text += chr((ord(char) - 65 + shift) % 26 + 65)
                else:
                    encrypted_text += chr((ord(char) - 97 + shift) % 26 + 97)
            else:
                encrypted_text += char
        return encrypted_text

    @staticmethod
    def decrypt(text, shift):
        decrypted_text = ""
        for char in text:
            if char.isalpha():
                if char.isupper():
                    decrypted_text += chr((ord(char) - 65 - shift) % 26 + 65)
                else:
                    decrypted_text += chr((ord(char) - 97 - shift) % 26 + 97)
            else:
                decrypted_text += char
        return decrypted_text