.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

loop:
ld 25, r4
ld 24, r5
ld 23, r6
ld 22, r7
ld 21, r8
st r4, 50
st r5, 49
st r6, 48
st r7, 47
st r8, 46
ld %0, r2
st r2, 5000
zjmp %:loop
