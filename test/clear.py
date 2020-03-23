s='abccddddcabc'
stack=[]
remove=False;
for i in range(len(s)):
    if not stack or stack[-1]!=s[i]:
        if remove:
            stack.pop()
            remove=False
            if stack and stack[-1] == s[i]:
                remove = True;
                continue;
        stack.append(s[i])
    else:
        remove = True
print("".join(stack));