async function fetchData() {
  return { id: 1, name: "Jane Doe", age: 30 };
}

async function getUserData() {
  console.log("Fetching user data...");
  const data = await fetchData();
  console.log("Data received:", data);
  return data;
}

getUserData().then((data) => {
  console.log("Processing data:", data);
});
