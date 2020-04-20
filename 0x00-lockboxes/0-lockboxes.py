#!/usr/bin/python3
def canUnlockAll(boxes):

    keys = [0]

    for key in keys:
        for new_key in boxes[key]:
            if new_key <= len(boxes) - 1 and new_key not in keys:
                keys.append(new_key)

    if len(keys) == len(boxes):
        return True
    else:
        return False
