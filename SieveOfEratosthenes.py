# Erastotenes Kalburu

def primes(num):
    sum=0
    sieve=[True]*num
    sieve[0],sieve[1]=False,False
    for i in range(2,num):
        if sieve[i]:
            sum+=1 
            for j in range(i*i,num,i):
                sieve[j]=False
    return sum

print(primes(90000000)) // total prime numbers up to 'num'