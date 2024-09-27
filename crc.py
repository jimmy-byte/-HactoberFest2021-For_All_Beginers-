def crc(msg, div, code='000'):
    msg = msg + code
    msg = list(msg)
    div = list(div)
    for i in range(len(msg)-len(code)):
        if msg[i] == '1':
            for j in range(len(div)):
                msg[i+j] = str((int(msg[i+j])+int(div[j]))%2)
    return ''.join(msg[-len(code):])



div = '1011'
msg = '11010011101100'
print('Input message:', msg)
print('Divisor:', div)
code = crc(msg, div)
print('Output code:', code)
print('Success:', crc(msg, div, code) == '000')