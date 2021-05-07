#!/usr/bin/python3
""" Count it! module
"""
import requests


def count_words(subreddit, word_list, first=True, after="", titles={}):
    """ Queries the Reddit API, parses the title of all hot articles,
        and prints a sorted count of given keywords
    """
    if first:
        word_list = list(set(word_list))

        for i, j in enumerate(word_list):
            word_list[i] = j.lower()

        dic = count_words(subreddit, word_list, False)

        if dic:
            for key, value in sorted(dic.items(), key=lambda x: (-x[1], x[0])):
                print("{}: {}".format(key, value))

        elif dic is None:
            return None

    else:
        base_url = 'https://www.reddit.com/r/'
        url = base_url + subreddit + "/hot.json"
        h = {'User-Agent': 'Reddit test'}
        p = {'limit': 100, 'after': after}
        res = requests.get(url, headers=h, params=p, allow_redirects=False)

        if res.status_code != 200:
            return None

        if after is None:
            return titles

        for i in res.json().get('data', {}).get('children'):
            title = i.get('data', {}).get('title').lower().split()
            for j in word_list:
                for t in title:
                    if j == t:
                        if j not in titles:
                            titles[j] = 1
                        else:
                            titles[j] += 1
        a = res.json().get('data', {}).get('after')
        return count_words(subreddit, word_list, False, a, titles)
