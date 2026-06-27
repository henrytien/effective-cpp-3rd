// @ts-check
const {themes} = require('prism-react-renderer');

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'Effective C++ 3rd Edition',
  tagline: '55 Specific Ways to Improve Your Programs and Designs',
  favicon: 'img/favicon.ico',

  url: 'https://henrytien.github.io',
  baseUrl: '/effective-cpp-3rd/',

  organizationName: 'henrytien',
  projectName: 'effective-cpp-3rd',

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  // SEO: generate sitemap
  trailingSlash: false,

  headTags: [
    {
      tagName: 'meta',
      attributes: {
        name: 'keywords',
        content: 'C++, Effective C++, Scott Meyers, C++20, design patterns, best practices',
      },
    },
    {
      tagName: 'meta',
      attributes: {
        name: 'author',
        content: 'henrytien',
      },
    },
  ],

  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: './sidebars.js',
          editUrl: 'https://github.com/henrytien/effective-cpp-3rd/edit/master/website/',
        },
        blog: false,
        theme: {
          customCss: './src/css/custom.css',
        },
        sitemap: {
          changefreq: 'weekly',
          priority: 0.5,
        },
        gtag: undefined,
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      metadata: [
        {name: 'description', content: 'Modern C++20 code examples for all 55 items in Effective C++ 3rd Edition by Scott Meyers. Cross-platform CMake build, interactive documentation.'},
        {property: 'og:image', content: 'https://henrytien.github.io/effective-cpp-3rd/img/og-image.png'},
      ],
      navbar: {
        title: 'Effective C++',
        items: [
          {
            type: 'docSidebar',
            sidebarId: 'mainSidebar',
            position: 'left',
            label: 'Items',
          },
          {
            href: 'https://github.com/henrytien/effective-cpp-3rd',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      algolia: {
        appId: 'TWXTCFI8O8',
        apiKey: '1f849676dd7627609cfd6306f279512c',
        indexName: 'effective-cpp-3rd',
        contextualSearch: true,
        searchPagePath: 'search',
      },
      footer: {
        style: 'dark',
        links: [
          {
            title: 'Docs',
            items: [
              { label: 'Introduction', to: '/docs/' },
            ],
          },
          {
            title: 'More',
            items: [
              { label: 'GitHub', href: 'https://github.com/henrytien/effective-cpp-3rd' },
              { label: 'Buy the Book', href: 'http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876' },
            ],
          },
        ],
        copyright: `Copyright ${new Date().getFullYear()} henrytien. Built with Docusaurus.`,
      },
      prism: {
        theme: themes.github,
        darkTheme: themes.dracula,
        additionalLanguages: ['cpp', 'cmake', 'bash'],
      },
    }),
};

module.exports = config;
