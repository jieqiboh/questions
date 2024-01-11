from dotenv import load_dotenv
from autokattis import Kattis
import os
from os.path import join, dirname

dotenv_path = join(dirname(__file__), '.env')
load_dotenv(dotenv_path)

KATTIS_PATH = os.path.join(os.path.dirname(dirname(__file__)), 'kattis')

# access variables and login
KATTIS_USERNAME = os.environ.get("KATTIS_USERNAME")
KATTIS_PW = os.environ.get("KATTIS_PW")
kt = Kattis(KATTIS_USERNAME, KATTIS_PW)

def generate_lines(p_dict, tried, lines):
    '''
    for a given dictionary of problems, generate lines that can be put into the README.md table
    tried is a boolean, if false it means the dict is of completed questions
    '''
    for d in p_dict:
        emoji = ":x:" if tried else ":white_check_mark:"
        problemid = d['id']
        diff = str(d['difficulty'])
        link = d['link']
        entry = "|" + "[" + problemid + "](" + link + ")"  +\
                "|" + diff +  "|" + emoji + "|  "
        
        lines.append(entry) 

# load completed and tried questions
solved_problems = kt.problems(show_solved=True, show_tried=False)
tried_problems = kt.problems(show_solved=False, show_tried=True)

lines = []

generate_lines(solved_problems, False, lines)
generate_lines(tried_problems, True, lines)

# Write to README.md
file = open(KATTIS_PATH + "/README.md","w")

file.write("Attempted: " + str(len(lines)) + "  \n")

file.write("|Problem ID|Difficulty|Completed|\n")
file.write("|:---|:---|:---|\n")

for row in lines:
    file.write(row + "\n")
file.close()

