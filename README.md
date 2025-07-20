<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1" />
<title>Problem Solving Bootcamp</title>
<style>
  @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@400;700&display=swap');

  body {
    margin: 0;
    background: linear-gradient(135deg, #6a11cb 0%, #2575fc 100%);
    font-family: 'Poppins', sans-serif;
    color: #fff;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
    padding: 2rem;
  }

  .container {
    background: rgba(255, 255, 255, 0.1);
    border-radius: 20px;
    padding: 2.5rem 3rem;
    max-width: 600px;
    box-shadow:
      0 8px 32px 0 rgba(31, 38, 135, 0.37),
      0 0 0 1px rgba(255, 255, 255, 0.18);
    backdrop-filter: blur(10px);
    -webkit-backdrop-filter: blur(10px);
    border: 1px solid rgba(255, 255, 255, 0.3);
  }

  h1 {
    font-size: 2.8rem;
    font-weight: 700;
    margin-bottom: 1rem;
    text-align: center;
    letter-spacing: 2px;
    text-transform: uppercase;
    background: linear-gradient(90deg, #ff6a00, #ee0979);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
  }

  p.intro {
    font-size: 1.15rem;
    font-weight: 500;
    margin-bottom: 2rem;
    text-align: center;
    color: #f0e9ffcc;
  }

  ul {
    list-style: none;
    padding-left: 0;
    columns: 2;
    gap: 1rem;
    font-weight: 600;
  }

  ul li {
    background: rgba(255, 255, 255, 0.15);
    margin: 0.5rem 0;
    padding: 0.7rem 1.2rem;
    border-radius: 12px;
    box-shadow: 0 4px 6px rgba(0,0,0,0.15);
    transition: background 0.3s ease, color 0.3s ease;
    cursor: default;
  }

  ul li:hover {
    background: #ff6a00;
    color: #fff;
    box-shadow: 0 6px 12px rgba(255, 106, 0, 0.7);
  }

  .footer {
    margin-top: 2.5rem;
    font-size: 1rem;
    font-weight: 500;
    text-align: center;
    color: #ffd6a5cc;
    letter-spacing: 0.05em;
  }

  @media (max-width: 480px) {
    ul {
      columns: 1;
    }
  }
</style>
</head>
<body>
  <div class="container">
    <h1>Problem Solving Bootcamp</h1>
    <p class="intro">
      Master essential algorithms and data structures in this bootcamp covering:
    </p>
    <ul>
      <li>Characters &amp; ASCII</li>
      <li>Logic &amp; Math</li>
      <li>Strings &amp; Arrays</li>
      <li>Matrices &amp; Two Pointers</li>
      <li>Stack &amp; Linked Lists</li>
      <li>Binary Search</li>
    </ul>
    <p class="footer">
      Build strong problem-solving skills to ace coding interviews and real-world challenges.
    </p>
  </div>
</body>
</html>
