import pytest
import tkinter as tk
import sys
sys.path.append("..")

from DCM_group9.database import Database

def test_register_user_empty():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_emptyusername():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_emptypassword():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_exists():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_correct():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "testsdsdsfff")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == True

def test_register_user_shortpassword():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_longpassword():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test" * 100)
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_longusername():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test" * 100)
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_shortusername():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "te")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_case_sensitivity_username():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "UsEr")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_user_invalid_characters_username():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user@user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

def test_register_morethan10users():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    # already 2 users in database
    for i in range(8):
        username_entry = tk.Entry(welcome_page)
        username_entry.insert(0, "test" + str(i))
        password_entry = tk.Entry(welcome_page)
        password_entry.insert(0, "test12345678")
        print(i)
        assert database_instance.register_user(welcome_page, username_entry, password_entry) == True
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance.register_user(welcome_page, username_entry, password_entry) == False

if __name__ == "__main__":
    pytest.main()
