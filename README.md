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
    background: linear-gradient(135deg, #4e54c8, #8f94fb);
    font-family: 'Poppins', sans-serif;
    color: #fff;
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
    padding: 1.5rem;
  }

  .container {
    background: #2a2f7a;
    padding: 2rem 3rem;
    border-radius: 16px;
    max-width: 600px;
    box-shadow: 0 8px 20px rgba(0,0,0,0.3);
    text-align: center;
  }

  h1 {
    font-size: 2.8rem;
    font-weight: 700;
    margin-bottom: 1rem;
    letter-spacing: 2px;
    background: linear-gradient(90deg, #ff416c, #ff4b2b);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
  }

  p.intro {
    font-size: 1.2rem;
    margin-bottom: 2rem;
    color: #dcdcdccc;
  }

  ul {
    list-style: none;
    padding-left: 0;
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(220px, 1fr));
    gap: 1rem;
    font-weight: 600;
  }

  ul li {
    background: #3f47b5;
    padding: 0.75rem 1rem;
    border-radius: 12px;
    transition: background-color 0.25s ease;
    cursor: default;
  }

  ul li:hover {
    background-color: #ff4b2b;
    color: #fff;
  }

  .footer {
    margin-top: 2rem;
    font-size: 1rem;
    font-weight: 500;
    color: #f0d1c1cc;
    letter-spacing: 0.05em;
  }

  @media (max-width: 480px) {
    .container {
      padding: 1.5rem 2rem;
    }
  }
</style>
</head>
<body>
  <div class="container">
    <h1>Problem Solving Bootcamp</h1>
    <p class="intro">Master essential algorithms and data structures in this bootcamp covering:</p>
    <ul>
      <li>Characters &amp; ASCII</li>
      <li>Logic &amp; Math</li>
      <li>Strings &amp; Arrays</li>
      <li>Matrices &amp; Two Pointers</li>
      <li>Stack &amp; Linked Lists</li>
      <li>Binary Search</li>
    </ul>
    <p class="footer">Build strong problem-solving skills to ace coding interviews and real-world challenges.</p>
  </div>
</body>
</html>
