import pytest
import tkinter as tk
import sys
sys.path.append("..")
from DCM_group9.database import Database

def homepage_screen():
    pass

def test_login_user_nonexistent():
    database_instance  = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test")
    assert database_instance .login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_correct():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == True

def test_login_user_wrongpassword():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "test" * 100)
    homepage_screen = tk.Tk()
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_wrongusername():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "test")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_empty():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_emptyusername():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_emptypassword():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_case_sensitivity_password():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "user")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "Password")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == False

def test_login_user_case_sensitivity_username():
    database_instance = Database("tests/test_database.json")
    welcome_page = tk.Tk()
    username_entry = tk.Entry(welcome_page)
    username_entry.insert(0, "UsEr")
    password_entry = tk.Entry(welcome_page)
    password_entry.insert(0, "password")
    assert database_instance.login_user(welcome_page, username_entry, password_entry, homepage_screen) == True


if __name__ == "__main__":
    pytest.main()
   