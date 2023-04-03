from itertools import izip_longest

def find_prefixes(strings):
    zipped = izip_longest(*strings, fillvalue='')
    for index, letters in enumerate(zipped):
        if index == 0:
            prefixes = letters  # assumes there will always be a prefix
        else:
            poss_prefixes = [prefix + letters[i] for i, prefix in enumerate(prefixes)]
            prefixes = [prefix if poss_prefixes.count(prefix) == letters.count(prefix)  # changed > 1 to == letters.count(prefix)
                        else prefixes[i] for i, prefix in enumerate(poss_prefixes)]
    return set(prefixes)

def find_prefix_suffixes(strings, prefixes):
    prefix_suffix = dict()
    for s in strings:
        for prefix in sorted(list(prefixes), key=lambda x: len(x), reverse=True):
            if s.startswith(prefix):
                if prefix in prefix_suffix:
                    prefix_suffix[prefix].add(s.replace(prefix, '', 1))
                else:
                    prefix_suffix[prefix] = set([s.replace(prefix, '', 1)])
    return prefix_suffix



s = raw_input("Enter grammar: ")

finished = []
not_finished = []

not_finished.append(s)
it = 1
while len(not_finished)>0:

    rules = not_finished.pop(0)

    r1,r2 = rules.split('->')

    s = list(r2.split('|'))

    kk = find_prefix_suffixes(s,find_prefixes(s))

    gama = []

    if(len(s)==len(kk)):
        finished.append(rules)
    else:

        f = r1+"->"
        itk = 1
        for i in kk:
            if(len(kk[i])==1):
                kkl = i
                for k in kk[i]:
                    kkl += k
                gama.append(kkl)
            else:
                if(itk!=1):
                    f+= "|"
                itk +=1
                f += i+r1
                for l in range(it):
                    f+="\'"
                ss = r1
                for l in range(it):
                    ss+="\'"
                ss+="->"
                g = len(kk[i])
                for k in kk[i]:
                    
                    if(k==''):
                        ss+="#"
                    else:
                        ss+= k
                    if(g!=1):
                        ss+= "|"

                    g-=1

                not_finished.append(ss)
                it +=1



    for i in gama:
        if(f[-1]!='>'):
            f += "|"
        f +=i

    finished.append(f)

finished = set(finished)

for k in finished:
    print k

