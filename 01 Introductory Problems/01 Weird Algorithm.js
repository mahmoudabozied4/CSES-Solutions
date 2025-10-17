const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
 
readline.question("", (n) => {
    while (n != 1) {
        process.stdout.write(n + " ");
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
 
    }
    process.stdout.write("1");
    readline.close();
});