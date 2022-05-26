import os
import random
import smtplib

def automatic_email():
    user = input("Enter your Name:")
    email = input("Enter your Email")
    number = input("Enter a number (1-9)")
    message = (f"Dear {user}, You have {number}, retakes in your semester")
    s = smttplib.SMTP('smtp gmail.com', 587)
    s = starttls()
    s.login("Yor gmail Account", "Your App Password")
    s.sendmail('&&&&&&&&&&&', email, message)
    print("Email Sent!")