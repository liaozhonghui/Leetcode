const a = [1, 2, 3, 4, 5];
async function get(type, key) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(1);
        }, 1000);
    })
}
async function cacheGet(key) {
    return get('children', key);
}

cacheGet()
    .then((data) => {
        console.log(data);
    })