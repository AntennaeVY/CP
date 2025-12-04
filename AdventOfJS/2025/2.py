def manufacture_gifts(gifts_to_produce):
    return [].extend([x.toy] * max(x.quantity, 0) for x in gifts_to_produce)
