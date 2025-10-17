const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
 
function fastPower(base, exponent) {
    let b = BigInt(base);
    let exp = BigInt(exponent);
    if (exp < 0n) {
        return 1 / Number(fastPower(b, -exp));
    }
    let result = 1n;
    while (exp > 0n) {
        if (exp % 2n === 1n) {
            result *= b;
        }
        b *= b;
        exp /= 2n;
    }
    return result;
}
 
readline.question("", (n) => {
    let ans = fastPower(2, n);
    ans = ans % 1000000007n
    process.stdout.write(ans.toString() + "\n");
    readline.close();
});