from bs4 import BeautifulSoup
import requests
import re

def submit(url, data):
    try:
        res = requests.post(url, data)
        print(f'[{res.status_code}] {res.reason}')
    except requests.exceptions.RequestException as e:
        print(f"Error submitting form: {e}")

def main():
    # Request and parse form
    view_url = input('Form link: ').strip()
    try:
        view_form = requests.get(view_url)
        view_form.raise_for_status()
    except requests.exceptions.RequestException as e:
        print(f"Failed to get form: {e}")
        return

    form = BeautifulSoup(view_form.content, 'html.parser')
    title = form.find(class_="freebirdFormviewerViewHeaderTitle")
    print(f'Found form: "{title.text if title else "Untitled"}"')

    # Prompt for each question, filling in data
    data = {}
    for index, item in enumerate(form.find_all(class_='freebirdFormviewerViewNumberedItemContainer')):
        question_params = item.find(class_='m2')
        if not question_params:
            continue
        qdata = re.findall(r'(?:\[\[)([0-9]*)', question_params.get('data-params'))
        if not qdata:
            continue
        question_title = item.find(class_='freebirdFormviewerComponentsQuestionBaseTitleDescContainer')
        if question_title:
            question_title = question_title.find(class_='freebirdFormviewerComponentsQuestionBaseTitle')
        data[f'entry.{qdata[0]}'] = input(
            f'\nQuestion {index+1}: '
            + (question_title.text if question_title else 'Unknown Question')
            + '\n'
        )

    if not data:
        print('No questions found.')
        return

    # Send form submissions
    url = view_url.replace('viewform', 'formResponse')
    submission_choice = input('\nReady to submit. Send continuously? (y/n)\n').strip().lower()
    if submission_choice in ['y', 'yes']:
        print('\nSpamming continuous submissions...')
        try:
            while True:
                submit(url, data)
        except KeyboardInterrupt:
            print("\nStopped by user.")
    elif submission_choice in ['n', 'now']:
        print('\nSending one submission...')
        submit(url, data)
    else:
        print('Cancelled by user.')

if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        print(f"Unexpected error: {error}")
